---
title: Controle de acesso de membro (C++) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- access control [C++]
- member access [C++]
- member-access control [C++]
ms.assetid: 2d596bca-56ad-4277-94e1-ce3db45fa14a
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 4d209e8f5e00460f1183a154f90bbdafd459b755
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="member-access-control-c"></a>Controle de acesso a membro (C++)
Controles de acesso permitem que você separe o [pública](../cpp/public-cpp.md) interface de uma classe do [privada](../cpp/private-cpp.md) detalhes de implementação e o [protegido](../cpp/protected-cpp.md) membros que são apenas para usam classes derivadas. O especificador de acesso se aplica a todos os membros declarados depois dele até que o especificador de acesso próximo seja encontrado.  
  
```  
class Point  
{  
public:                   
    Point( int, int ) // Declare public constructor.;  
    Point();// Declare public default constructor.  
    int &x( int ); // Declare public accessor.  
    int &y( int ); // Declare public accessor.  
  
private:                 // Declare private state variables.  
    int _x;  
    int _y;  
  
protected:      // Declare protected function for derived classes only.  
    Point ToWindowCoords();  
};  
  
```  
  
 O acesso padrão é `private` em uma classe, e `public` em uma struct ou união. Especificadores de acesso em uma classe podem ser usado qualquer número de vezes em qualquer ordem. A alocação de armazenamento para objetos de tipos de classe depende da implementação, mas é garantido que os membros receberão endereços de memória sucessivamente mais altos entre especificadores de acesso.  
  
### <a name="member-access-control"></a>Controle de acesso de membros  
  
|Tipo de acesso|Significado|  
|--------------------|-------------|  
|[private](../cpp/private-cpp.md)|Os membros de classe declarados como `private` podem ser usados apenas pelas funções membro e por amigos (classes ou funções) da classe.|  
|[protected](../cpp/protected-cpp.md)|Os membros de classe declarados como `protected` podem ser usados pelas funções membro e por amigos (classes ou funções) da classe. Além disso, eles podem ser usados por classes derivadas da classe.|  
|[public](../cpp/public-cpp.md)|Membros de classe declarados como **pública** pode ser usado por qualquer função.|  
  
 O controle de acesso ajuda a evitar que você use objetos de maneiras que não sejam as destinadas a eles. Essa proteção será perdida quando as conversões de tipo explícitas (casts) forem executadas.  
  
> [!NOTE]
>  O controle de acesso é igualmente aplicável a todos os nomes: funções membro, dados de membro, classes aninhadas e enumeradores.  
  
## <a name="access-control-in-derived-classes"></a>Controle de acesso em Classes derivadas  
 Dois fatores controlam quais membros de uma classe base são acessíveis em uma classe derivada; esses mesmos fatores controlam o acesso aos membros herdados na classe derivada:  
  
-   Se a classe derivada declara a classe base usando o **pública** acessar especificador no *classe head* (*cabeçalho de classe* é descrita na seção gramática [ Definindo tipos de classe](http://msdn.microsoft.com/en-us/e8c65425-0f3a-4dca-afc2-418c3b1e57da)).  
  
-   Qual é o acesso ao membro na classe base.  
  
 A tabela a seguir mostra a interação entre esses fatores e como determinar o acesso do membro da classe base.  
  
### <a name="member-access-in-base-class"></a>Acesso do membro na classe base  
  
|particulares|protegidos|Público|  
|-------------|---------------|------------|  
|Sempre inacessível independentemente do acesso de derivação|Privado na classe derivada se você usar derivação particular|Privado na classe derivada se você usar derivação particular|  
||Protegido na classe derivada se você usar derivação protegida|Protegido na classe derivada se você usar derivação protegida|  
||Protegido na classe derivada se você usar derivação pública|Público na classe derivada se você usar derivação pública|  
  
 O exemplo a seguir ilustra isto:  
  
```  
// access_specifiers_for_base_classes.cpp  
class BaseClass  
{  
public:  
    int PublicFunc();    // Declare a public member.  
protected:  
    int ProtectedFunc(); // Declare a protected member.  
private:  
    int PrivateFunc();   // Declare a private member.  
};  
  
// Declare two classes derived from BaseClass.  
class DerivedClass1 : public BaseClass  
{  
};  
  
class DerivedClass2 : private BaseClass  
{  
};  
  
int main()  
{  
}  
```  
  
 Em `DerivedClass1`, a função de membro `PublicFunc` é um membro público e `ProtectedFunc` é um membro protegido porque `BaseClass` é uma classe base pública. `PrivateFunc` é particular a `BaseClass`, e inacessível a quaisquer classes derivadas.  
  
 Em `DerivedClass2`, as funções `PublicFunc` e `ProtectedFunc` são consideradas membros particulares porque `BaseClass` é uma classe base particular. Novamente, `PrivateFunc` é particular a `BaseClass`, e inacessível a quaisquer classes derivadas.  
  
 Você pode declarar uma classe derivada sem um especificador de acesso de classe base. Nesse caso, a derivação é considerada privada se a declaração de classe derivada usa o **classe** palavra-chave. A derivação será considerada pública se a declaração de classe derivada usar a palavra-chave `struct`. Por exemplo, o código a seguir:  
  
```  
class Derived : Base  
...  
```  
  
 equivale a:  
  
```  
class Derived : private Base  
...  
```  
  
 Da mesma forma, o código a seguir:  
  
```  
struct Derived : Base  
...  
```  
  
 equivale a:  
  
```  
struct Derived : public Base  
...  
```  
  
 Observe que os membros declarados como tendo acesso particular não são acessíveis a funções ou classes derivadas a menos que essas funções ou classes sejam declaradas usando a declaração `friend` na classe base.  
  
 Um **união** tipo não pode ter uma classe base.  
  
> [!NOTE]
>  Ao especificar uma classe base particular, recomendamos usar explicitamente a palavra-chave `private` para que os usuários da classe derivada entendam o acesso do membro.  
  
## <a name="access-control-and-static-members"></a>Controle de acesso e membros estáticos  
 Quando você especifica uma classe base como `private`, isso só afeta os membros não estáticos. Os membros estáticos públicos ainda são acessíveis nas classes derivadas. No entanto, o acesso a membros da classe base usando ponteiros, referências ou objetos pode exigir uma conversão, quando então o controle de acesso é aplicado novamente. Considere o exemplo a seguir:  
  
```  
// access_control.cpp  
class Base  
{  
public:  
    int Print();             // Nonstatic member.  
    static int CountOf();    // Static member.  
};  
  
// Derived1 declares Base as a private base class.  
class Derived1 : private Base  
{  
};  
// Derived2 declares Derived1 as a public base class.  
class Derived2 : public Derived1  
{  
    int ShowCount();    // Nonstatic member.  
};  
// Define ShowCount function for Derived2.  
int Derived2::ShowCount()  
{  
   // Call static member function CountOf explicitly.  
    int cCount = Base::CountOf();     // OK.  
  
   // Call static member function CountOf using pointer.  
    cCount = this->CountOf();  // C2247. Conversion of  
                               //  Derived2 * to Base * not  
                               //  permitted.  
    return cCount;  
}  
```  
  
 No código acima, o controle de acesso proíbe a conversão de um ponteiro para `Derived2` em um ponteiro para `Base`. O **isso** ponteiro implicitamente é do tipo `Derived2 *`. Para selecionar o `CountOf` função **isso** deve ser convertido no tipo `Base *`. Essa conversão não é permitida porque `Base` é uma classe base indireta privada para `Derived2`. A conversão em um tipo de classe base privada é aceitável apenas no caso de ponteiros para as classes derivadas imediatas. Consequentemente, os ponteiros do tipo `Derived1 *` podem ser convertidos no tipo `Base *`.  
  
 Observe que chamar a função `CountOf` explicitamente, sem usar um ponteiro, uma referência ou um objeto para selecioná-la, não implica em nenhuma conversão. Consequentemente, a chamada é permitida.  
  
 Os membros e amigos de uma classe derivada, `T`, podem converter um ponteiro para `T` em um ponteiro para uma classe base direta privada de `T`.  
  
## <a name="access-to-virtual-functions"></a>Acesso a funções virtuais  
 O controle de acesso aplicadas a [virtual](../cpp/virtual-cpp.md) funções é determinado pelo tipo usado para fazer com que a função de chamada. Substituir declarações da função não afeta o controle de acesso para um determinado tipo. Por exemplo:  
  
```  
// access_to_virtual_functions.cpp  
class VFuncBase  
{  
public:  
    virtual int GetState() { return _state; }  
protected:  
    int _state;  
};  
  
class VFuncDerived : public VFuncBase  
{  
private:  
    int GetState() { return _state; }  
};  
  
int main()  
{  
   VFuncDerived vfd;             // Object of derived type.  
   VFuncBase *pvfb = &vfd;       // Pointer to base type.  
   VFuncDerived *pvfd = &vfd;    // Pointer to derived type.  
   int State;  
  
   State = pvfb->GetState();     // GetState is public.  
   State = pvfd->GetState();     // C2248 error expected; GetState is private;  
}  
```  
  
 No exemplo anterior, chamar a função virtual `GetState` usando um ponteiro para o tipo `VFuncBase` chama `VFuncDerived::GetState`, e `GetState` é tratada como pública. No entanto, chamar `GetState` usando um ponteiro para o tipo `VFuncDerived` é uma violação de controle de acesso porque `GetState` é declarado como particular na classe `VFuncDerived`.  
  
> [!CAUTION]
>  A função virtual `GetState` pode ser chamada usando um ponteiro para a classe base `VFuncBase`. Isso não significa que a função chamada seja a versão da classe base dessa função.  
  
## <a name="access-control-with-multiple-inheritance"></a>Controle de acesso com várias heranças  
 Em células entrelaçadas de herança múltipla que envolvem classes base virtuais, um nome determinado pode ser acessado por mais de um caminho. Como o controle de acesso diferente pode ser aplicado ao longo desses caminhos diferentes, o compilador escolhe o caminho que fornece o maior acesso. Veja a figura a seguir.  
  
 ![Acesso ao longo de caminhos de um gráfico de herança](../cpp/media/vc38v91.gif "vc38V91")  
Acesso ao longo dos caminhos de um gráfico de herança  
  
 Na figura, um nome declarado na classe `VBase` é sempre acessado pela classe `RightPath`. O caminho à direita é mais acessível porque `RightPath` declara `VBase` como uma classe base pública, enquanto que `LeftPath` declara `VBase` como particular.  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)
