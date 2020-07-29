---
title: Operador static_cast
ms.date: 11/04/2016
f1_keywords:
- static_cast_cpp
helpviewer_keywords:
- static_cast keyword [C++]
ms.assetid: 1f7c0c1c-b288-476c-89d6-0e2ceda5c293
ms.openlocfilehash: 8551d41417647ee4f759e2547e2c1909c59d78cd
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87213197"
---
# <a name="static_cast-operator"></a>Operador static_cast

Converte uma *expressão* para o tipo de *ID-tipo,* com base apenas nos tipos que estão presentes na expressão.

## <a name="syntax"></a>Sintaxe

```
static_cast <type-id> ( expression )
```

## <a name="remarks"></a>Comentários

No padrão C++, nenhuma verificação de tipo de tempo de execução é feita para ajudar a garantir a segurança da conversão. No C++/CX, uma verificação de tempo de compilação e de runtime é executada. Para obter mais informações, consulte [Conversão](casting.md).

O **`static_cast`** operador pode ser usado para operações como converter um ponteiro para uma classe base em um ponteiro para uma classe derivada. Essas conversões não são sempre seguras.

Em geral, você usa **`static_cast`** quando deseja converter tipos de dados numéricos, como enums para ints ou ints como floats, e você tem certeza dos tipos de dados envolvidos na conversão. **`static_cast`** as conversões não são tão seguras quanto as **`dynamic_cast`** conversões, pois **`static_cast`** não há verificação de tipo em tempo de execução, enquanto **`dynamic_cast`** o faz. R **`dynamic_cast`** para um ponteiro ambíguo falhará, enquanto um **`static_cast`** retorna como se nada estivesse errado, isso pode ser perigoso. Embora **`dynamic_cast`** as conversões sejam mais seguras, **`dynamic_cast`** o só funciona em ponteiros ou referências, e a verificação de tipo em tempo de execução é uma sobrecarga. Para obter mais informações, consulte [operador de dynamic_cast](../cpp/dynamic-cast-operator.md).

No exemplo a seguir, a linha `D* pd2 = static_cast<D*>(pb);` não é segura porque `D` pode ter campos e métodos que não estão em `B`. No entanto, a linha `B* pb2 = static_cast<B*>(pd);` é uma conversão segura porque `D` sempre contém tudo de `B`.

```cpp
// static_cast_Operator.cpp
// compile with: /LD
class B {};

class D : public B {};

void f(B* pb, D* pd) {
   D* pd2 = static_cast<D*>(pb);   // Not safe, D can have fields
                                   // and methods that are not in B.

   B* pb2 = static_cast<B*>(pd);   // Safe conversion, D always
                                   // contains all of B.
}
```

Em contraste com [dynamic_cast](../cpp/dynamic-cast-operator.md), nenhuma verificação de tempo de execução é feita na **`static_cast`** conversão de `pb` . O objeto apontado por `pb` não pode ser um objeto do tipo `D`, pois, nesse caso, o uso de `*pd2` seria desastroso. Por exemplo, chamar uma função que é membro da classe `D`, mas não da classe `B`, poderá resultar em uma violação de acesso.

Os **`dynamic_cast`** **`static_cast`** operadores e movem um ponteiro em toda a hierarquia de classe. No entanto, **`static_cast`** depende exclusivamente das informações fornecidas na instrução cast e, portanto, pode não ser segura. Por exemplo:

```cpp
// static_cast_Operator_2.cpp
// compile with: /LD /GR
class B {
public:
   virtual void Test(){}
};
class D : public B {};

void f(B* pb) {
   D* pd1 = dynamic_cast<D*>(pb);
   D* pd2 = static_cast<D*>(pb);
}
```

Se `pb` apontar para um objeto do tipo `D`, `pd1` e `pd2` obterão o mesmo valor. Eles também obterão o mesmo valor se `pb == 0`.

Se `pb` apontar para um objeto do tipo `B` e não para a `D` classe completa, então **`dynamic_cast`** saberá o suficiente para retornar zero. No entanto, **`static_cast`** o se baseia na declaração do programador que `pb` aponta para um objeto do tipo `D` e simplesmente retorna um ponteiro para o `D` objeto esperado.

Consequentemente, o **`static_cast`** pode fazer o inverso de conversões implícitas, caso em que os resultados são indefinidos. Ele é deixado ao programador para verificar se os resultados de uma **`static_cast`** conversão são seguros.

Esse comportamento também se aplica a tipos diferentes dos tipos de classe. Por exemplo, **`static_cast`** pode ser usado para converter de um int para um **`char`** . No entanto, o resultado **`char`** pode não ter bits suficientes para manter o **`int`** valor inteiro. Novamente, é deixada para o programador verificar se os resultados de uma **`static_cast`** conversão são seguros.

O **`static_cast`** operador também pode ser usado para executar qualquer conversão implícita, incluindo conversões padrão e conversões definidas pelo usuário. Por exemplo:

```cpp
// static_cast_Operator_3.cpp
// compile with: /LD /GR
typedef unsigned char BYTE;

void f() {
   char ch;
   int i = 65;
   float f = 2.5;
   double dbl;

   ch = static_cast<char>(i);   // int to char
   dbl = static_cast<double>(f);   // float to double
   i = static_cast<BYTE>(ch);
}
```

O **`static_cast`** operador pode converter explicitamente um valor integral em um tipo de enumeração. Se o valor do tipo integral não estiver dentro do intervalo de valores de enumeração, o valor de enumeração resultante será indefinido.

O **`static_cast`** operador converte um valor de ponteiro nulo para o valor de ponteiro nulo do tipo de destino.

Qualquer expressão pode ser convertida explicitamente para o tipo void pelo **`static_cast`** operador. O tipo void de destino pode, opcionalmente **`const`** , incluir o **`volatile`** atributo, ou **`__unaligned`** .

O **`static_cast`** operador não pode converter os **`const`** **`volatile`** atributos, ou **`__unaligned`** . Consulte [operador de const_cast](../cpp/const-cast-operator.md) para obter informações sobre como remover esses atributos.

**C++/CLI:** Devido ao perigo de executar conversões não verificadas sobre um coletor de lixo realocado, o uso do **`static_cast`** deve estar apenas no código de desempenho crítico quando você tiver certeza de que ele funcionará corretamente. Se você precisar usar **`static_cast`** o no modo de versão, substitua-o por [safe_cast](../extensions/safe-cast-cpp-component-extensions.md) em suas compilações de depuração para garantir o sucesso.

## <a name="see-also"></a>Confira também

[Operadores de conversão](../cpp/casting-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
