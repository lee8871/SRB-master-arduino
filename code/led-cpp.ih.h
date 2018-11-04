

#define __class_name(n) __class_##n
#define _class_name(n) __class_name(n)
#define class_name _class_name(instance_name)


class class_name
{
public :
	inline void on();
	inline void off();
	inline void tog();
	inline void init();
};
inline void class_name::on(){
	PORTx set bit_;
}
inline void class_name::off(){
	PORTx clr bit_;
}
inline void class_name::tog(){
	PORTx ^= bit_;
}
inline void class_name::init(){
	DDRx set bit_;
	PORTx clr bit_;
}

extern class_name instance_name;

#undef PORTx
#undef DDRx
#undef bit_
#undef instance_name

#undef __class_name
#undef _class_name
#undef class_name
