---
title: Operador static_cast
ms.date: 11/04/2016
f1_keywords:
- static_cast_cpp
helpviewer_keywords:
- static_cast keyword [C++]
ms.assetid: 1f7c0c1c-b288-476c-89d6-0e2ceda5c293
ms.openlocfilehash: 37708bf50b28eb120af8e8a79e770c3121e6f509
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80178581"
---
# <a name="static_cast-operator"></a>Operador static_cast

Converte uma *expressão* para o tipo de *ID-tipo,* com base apenas nos tipos que estão presentes na expressão.

## <a name="syntax"></a>Sintaxe

```
static_cast <type-id> ( expression )
```

## <a name="remarks"></a>Comentários

No padrão C++, nenhuma verificação de tipo de tempo de execução é feita para ajudar a garantir a segurança da conversão. No C++/CX, uma verificação de tempo de compilação e de runtime é executada. Para obter mais informações, consulte [Conversão](casting.md).

O operador **static_cast** pode ser usado para operações como converter um ponteiro para uma classe base em um ponteiro para uma classe derivada. Essas conversões não são sempre seguras.

Em geral, você usa **static_cast** quando deseja converter tipos de dados numéricos, como enums para ints ou ints como floats, e você tem certeza dos tipos de dados envolvidos na conversão. **static_cast** conversões não são tão seguras quanto **dynamic_cast** conversões, porque **static_cast** não faz verificação de tipo em tempo de execução, enquanto **dynamic_cast** . Um **dynamic_cast** a um ponteiro ambíguo falhará, enquanto um **static_cast** retornará como se nada estivesse errado; Isso pode ser perigoso. Embora **dynamic_cast** conversões sejam mais seguras, **dynamic_cast** funciona apenas em ponteiros ou referências, e a verificação de tipo em tempo de execução é uma sobrecarga. Para obter mais informações, consulte [operador de dynamic_cast](../cpp/dynamic-cast-operator.md).

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

Em contraste com [dynamic_cast](../cpp/dynamic-cast-operator.md), nenhuma verificação de tempo de execução é feita na conversão de **static_cast** de `pb`. O objeto apontado por `pb` não pode ser um objeto do tipo `D`, pois, nesse caso, o uso de `*pd2` seria desastroso. Por exemplo, chamar uma função que é membro da classe `D`, mas não da classe `B`, poderá resultar em uma violação de acesso.

Os operadores **dynamic_cast** e **static_cast** movem um ponteiro em toda a hierarquia de classes. No entanto, **static_cast** depende exclusivamente das informações fornecidas na instrução cast e, portanto, pode não ser segura. Por exemplo:

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

Se `pb` apontar para um objeto do tipo `B` e não para a classe `D` completa, **dynamic_cast** saberá o suficiente para retornar zero. No entanto, **static_cast** se baseia na declaração do programador que `pb` aponta para um objeto do tipo `D` e simplesmente retorna um ponteiro para isso que deveria `D` objeto.

Consequentemente, **static_cast** pode fazer o inverso de conversões implícitas; nesse caso, os resultados são indefinidos. Ele é deixado ao programador para verificar se os resultados de uma conversão de **static_cast** são seguros.

Esse comportamento também se aplica a tipos diferentes dos tipos de classe. Por exemplo, **static_cast** pode ser usado para converter de um int em um **Char**. No entanto, o **caractere** resultante pode não ter bits suficientes para manter **todo o valor inteiro.** Novamente, é deixada para o programador verificar se os resultados de uma conversão de **static_cast** são seguros.

O operador de **static_cast** também pode ser usado para executar qualquer conversão implícita, incluindo conversões padrão e conversões definidas pelo usuário. Por exemplo:

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

O operador **static_cast** pode converter explicitamente um valor integral em um tipo de enumeração. Se o valor do tipo integral não estiver dentro do intervalo de valores de enumeração, o valor de enumeração resultante será indefinido.

O operador **static_cast** converte um valor de ponteiro nulo para o valor de ponteiro nulo do tipo de destino.

Qualquer expressão pode ser convertida explicitamente para o tipo void pelo operador de **static_cast** . O tipo void de destino pode, opcionalmente, incluir o atributo **const**, **volatile**ou **__unaligned** .

O operador de **static_cast** não pode converter os atributos **const**, **volatile**ou **__unaligned** . Consulte [operador de const_cast](../cpp/const-cast-operator.md) para obter informações sobre como remover esses atributos.

**C++/CLI:** Devido ao perigo de executar conversões não verificadas sobre um coletor de lixo realocado, o uso de **static_cast** só deve estar no código de desempenho crítico quando você tiver certeza de que ele funcionará corretamente. Se você precisar usar **static_cast** no modo de versão, substitua-o por [safe_cast](../extensions/safe-cast-cpp-component-extensions.md) em suas compilações de depuração para garantir o sucesso.

## <a name="see-also"></a>Confira também

[Operadores de conversão](../cpp/casting-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
