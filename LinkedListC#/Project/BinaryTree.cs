using List;

namespace Tree
{
    class Sheet<Type>
    {
        private string name { get; set; }
        private Type value { get; set; }
        public Sheet(string name, Type value)
        {
            this.name = name;
            this.value = value;
        }
        public string GetName()
        {
            return name;
        }
        public void SetName(string name)
        {
            this.name = name;
        }
        public Type GetValue()
        {
            return value;
        }
        public void SetValue(Type value)
        {
            this.value = value;
        }
    }
    class Branch<Type>
    {
        private string name { get; set; }
        private List<Sheet<Type>> sheets { get; set; }
        private List<Branch<Type>> branches { get; set; }
        private Branch<Type> parent { set; get; } = null;
        public Branch(string name, Branch<Type> parent)
        {
            this.name = name;
            this.parent = parent;
            this.sheets = new List<Sheet<Type>>();
            this.branches = new List<Branch<Type>>();
        }
        public string GetName()
        {
            return name;
        }
        public void SetName(string name)
        {
            this.name = name;
        }
        public Branch<Type>[] GetBranches()
        {
            return branches.GetArray();
        }
        public void AddBranch(Branch<Type> branch)
        {
            this.branches.Push(branch);
        }
        public void AddBranch(string name)
        {
            this.branches.Push(new Branch<Type>(name, this));
        }
        public Sheet<Type>[] GetSheets()
        {
            return sheets.GetArray();
        }
        public void AddSheets(Sheet<Type> sheet)
        {
            this.sheets.Push(sheet);
        }
        public void AddSheets(string name, Type value)
        {
            this.sheets.Push(new Sheet<Type>(name, value));
        }
    }
    class Tree<Type>
    {
        private Branch<Type> root { get; set; }
        public Tree(string name)
        {
            this.root = new Branch<Type>(name, null);
        }
        public Branch<Type> GetRoot()
        {
            return root;
        }
    }
}


