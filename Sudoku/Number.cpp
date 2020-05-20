class Number{
	private:
		int row;
		int column;
		int Value;
		bool isChangeable;
		
	public:
		int getRow(){
			return row;
		}	
		int getColumn(){
			return column;
		}
		int getValue(){
			return Value;
		}
		bool getStatus(){
			return isChangeable;
		}
		
		void updateRow(int row){
			this->row=row;
		}
		void updateColumn(int column){
			this->column=column;
		}
		void updateValue(int Value){
			this->Value=Value;
		}
		
		Number(int Value,int row,int column){
			this->Value=Value;
			this->row=row;
			this->column=column;
			isChangeable=true;
		}
		Number(int Value,int row,int column,bool C){
			this->Value=Value;
			this->row=row;
			this->column=column;
			isChangeable=C;
		}
};
