#include "lintcode_common.h"

class lintcode_7 {
public:
	void splitString(const string &s, vector<string> &v, string c)
	{
		string::size_type pos1, pos2;
		pos2 = s.find(c);
		pos1 = 0;
		while (string::npos != pos2)
		{
			v.push_back(s.substr(pos1, pos2 - pos1));
			pos1 = pos2 + c.size();
			pos2 = s.find(c, pos1);
		}
		if (pos1 != s.length())
			v.push_back(s.substr(pos1));
	}
	/**
	* This method will be invoked first, you should design your own algorithm
	* to serialize a binary tree which denote by a root node to a string which
	* can be easily deserialized by your own "deserialize" method later.
	*/
	string serialize(TreeNode * root) {
		if (root == NULL) return "";
		vector<TreeNode *> vctNote;
		string strOut;
		vctNote.push_back(root);
		do
		{
			vector<TreeNode *> vctTemp;
			for (size_t i = 0; i < vctNote.size(); ++i)
			{
				if (vctNote[i] != 0)
				{
					strOut += to_string(vctNote[i]->val) + ",";
					if (vctNote[i]->left == NULL && vctNote[i]->right == NULL)
						strOut += "#,";
					else
					{
						vctTemp.push_back(vctNote[i]->left);
						vctTemp.push_back(vctNote[i]->right);
					}
				}
				else
					strOut += "$,";
			}
			vctNote = vctTemp;
		} while (vctNote.size() > 0);
		return strOut;
	}

	/**
	* This method will be invoked second, the argument data is what exactly
	* you serialized at method "serialize", that means the data is not given by
	* system, it's given by your own serialize method. So the format of data is
	* designed by yourself, and deserialize it here as you serialize it in
	* "serialize" method.
	*/
	TreeNode * deserialize(string &data) {
		vector<string> vctSplit;
		splitString(data, vctSplit, ",");
		if (vctSplit.empty())
			return NULL;
		TreeNode * pHead = new TreeNode(stoi(vctSplit[0], nullptr, 0));
		vector<TreeNode *> vctNote;
		vctNote.push_back(pHead);
		size_t i = 1;
		while (i < vctSplit.size())
		{
			vector<TreeNode *> vctTemp;
			for (size_t n = 0; n < vctNote.size(); ++n)
			{
				if (i < vctSplit.size() && vctSplit[i] != "$")
				{
					TreeNode * pTemp = new TreeNode(stoi(vctSplit[i], nullptr, 0));
					vctNote[n]->left = pTemp;
					if (i + 1 < vctSplit.size())
					{
						if (vctSplit[i + 1] == "#")
							++i;
						else
							vctTemp.push_back(pTemp);
					}
				}
				if (i + 1 < vctSplit.size() && vctSplit[i + 1] != "$")
				{
					TreeNode * pTemp = new TreeNode(stoi(vctSplit[i + 1], nullptr, 0));
					vctNote[n]->right = pTemp;
					if (i + 2 < vctSplit.size())
					{
						if (vctSplit[i + 2] == "#")
							++i;
						else
							vctTemp.push_back(pTemp);
					}
				}
				i += 2;
			}
			vctNote = vctTemp;
		}
		return pHead;
	}
};