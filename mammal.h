#ifndef mammal
#define mammal
#undef mammal


// Implement a base Struct called mammal

struct Mammal
{
    void (*constructor) (struct Mammal* this); // pointer to function of void return and void arg
    void (*destructor) (struct Mammal* this);
    struct vTable* vptr; // pointer to vTable structure of array pointers
};

// VTable will contain a series of function pointers that will be reassigned with each construction
// Of the structs
struct vTable
{
    void (*speak)(); // call function in vTable of that structure
};

// Derived class Dog
struct Dog
{
    // Allows pointer to our struct
    struct Mammal base;
    void (*construct)(struct Dog* this);
    void (*destruct)(struct Dog* this);

};
void speakmam(){printf("Mammal noises.\n"); }
/*
    Void function allocates a vTable
    structure in the heap, initalizes
    mammal structs members
*/
void construct_Mammal(struct Mammal* this)
{
    printf("Calling Mammal Constructor.\n");
    this->vptr = (struct vTable*)malloc(sizeof(struct vTable));
    this->vptr->speak = speakmam;
}

/*
    Free vTables back to OS
*/
void destruct_Mammal(struct Mammal* this)
{
    printf("Calling Mammal Destructor.\n");
    free(this->vptr); // free vTable
}
void dogspeak()
{
    printf("Bark!\n");
}


/*
    Void function constructs Base class and
    reassign vTable function pointers corre-
    ponding to Dog functions
*/
void construct_Dog(struct Dog* this)
{
    // Construct Base member first
    construct_Mammal((struct Mammal*)this);
    // Now reassign vTable memebrs
    this->base.vptr->speak = dogspeak;
    printf("Calling dog constructor.\n");
}

void destruct_Dog(struct Dog* this)
{
    destruct_Mammal((struct Mammal*)this); // destruct mammal first
    printf("Calling on dog destructor.\n");
}

struct Cat
{
    struct Mammal base;
    void (*constructor)(struct Cat* this);
    void (*destructor)(struct Cat* this);
};

void catspeak()
{
    printf("Meow!\n");
}

void construct_Cat(struct Cat* this)
{
    // construct mammal first
    construct_Mammal((struct Mammal*)this);
    // reassign vTable func pointer
    this->base.vptr->speak = catspeak;
    printf("Calling cat constructor.\n");
}

void destruct_Cat(struct Cat* this)
{
    // Destruct mammal first
    destruct_Mammal((struct Mammal*)this);
    printf("Calling on cat destructor.\n");
}

void horsespeak(){printf("YeeHaa\n");}

struct Horse
{
    struct Mammal base;
    void(*constructor) (struct Horse* this);
    void (*destructor) (struct HOrse* this);
};

void construct_Horse(struct Horse *this)
{
    // construct mammal
    construct_Mammal((struct Mammal*)this);
    // reassign virtual table ptrs
    this->base.vptr->speak = horsespeak;
    printf("Calling constructor of Horse.\n");
}

void destruct_Horse(struct Horse* this)
{
    printf("Calling destructor of Horse.\n");
    // destruct mammal
    destruct_Mammal((struct Mammal*)this);
}

struct Pig
{
    struct Mammal base;
    void(*constructor)(struct Pig* this);
    void (*destructor)(struct Pig  *this);
};
void pigspeak(){printf("Onik\n"); }

void construct_Pig(struct Pig* this)
{
    // construct base first
    construct_Mammal((struct Mammal*)this);
    printf("Calling pig constructor.\n");
    // reassign vTable func ptrs
    this->base.vptr->speak= pigspeak;
}

void destruct_Pig(struct Pig* this)
{
    printf("Calling pig destructor.\n");
    destruct_Mammal((struct Mammal* )this);

}

struct Mammal INITMM = {construct_Mammal,destruct_Mammal,{speakmam}};
struct Dog INITDG = {{0,0},construct_Dog,destruct_Dog};
struct Cat INITCT = {{0,0},construct_Cat,destruct_Cat};
struct Horse INITHE = {{0,0},construct_Horse,destruct_Pig};
struct Pig INITPG = {{0,0},construct_Pig,destruct_Pig};
#endif
 // mammal
