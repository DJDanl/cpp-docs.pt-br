---
title: Operador static_cast
ms.date: 11/04/2016
f1_keywords:
- static_cast_cpp
helpviewer_keywords:
- static_cast keyword [C++]
ms.assetid: 1f7c0c1c-b288-476c-89d6-0e2ceda5c293
ms.openlocfilehash: dca6d5297379e6ddc1c70dba80f35f2f55672e49
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62267122"
---
# <a name="staticcast-operator"></a>Operador static_cast

Converte um *expressão* para o tipo de *id de tipo,* com base apenas nos tipos que estão presentes na expressão.

## <a name="syntax"></a>Sintaxe

```
static_cast <type-id> ( expression )
```

## <a name="remarks"></a>Comentários

No padrão C++, nenhuma verificação de tipo de tempo de execução é feita para ajudar a garantir a segurança da conversão. No C++/CX, uma verificação de tempo de compilação e de tempo de execução é executada. Para obter mais informações, consulte [Conversão](casting.md).

O **static_cast** operador pode ser usado para operações como converter um ponteiro para uma classe base para um ponteiro para uma classe derivada. Essas conversões não são sempre seguras.

Em geral você usar **static_cast** quando você deseja converter tipos de dados numéricos, como enums, em ints ou ints em floats e estão certos tipos de dados envolvidos na conversão. **static_cast** as conversões não são tão seguras quanto **dynamic_cast** conversões, pois **static_cast** verifica nenhum tipo de tempo de execução, enquanto **dynamic_cast** faz. Um **dynamic_cast** um ponteiro ambíguo falhará, enquanto um **static_cast** retorna como se nada estivesse errado; isso pode ser perigoso. Embora **dynamic_cast** conversões são mais seguras, **dynamic_cast** somente funciona em ponteiros ou referências e a verificação de tipo de tempo de execução é uma sobrecarga. Para obter mais informações, consulte [operador dynamic_cast](../cpp/dynamic-cast-operator.md).

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

Em contraste com [dynamic_cast](../cpp/dynamic-cast-operator.md), nenhuma verificação de tempo de execução é feita na **static_cast** conversão de `pb`. O objeto apontado por `pb` não pode ser um objeto do tipo `D`, pois, nesse caso, o uso de `*pd2` seria desastroso. Por exemplo, chamar uma função que é membro da classe `D`, mas não da classe `B`, poderá resultar em uma violação de acesso.

O **dynamic_cast** e **static_cast** operadores movem um ponteiro ao longo de uma hierarquia de classe. No entanto, **static_cast** baseia-se exclusivamente nas informações fornecidas na instrução de conversão e, portanto, não pode ser seguro. Por exemplo:

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

Se `pb` aponta para um objeto do tipo `B` e não para a conclusão `D` class, e então **dynamic_cast** terá conhecimento suficiente para retornar zero. No entanto, **static_cast** depende da asserção do programador que `pb` aponta para um objeto do tipo `D` e simplesmente retorna um ponteiro ao suposto `D` objeto.

Consequentemente, **static_cast** pode fazer o inverso de conversões implícitas, caso em que os resultados são indefinidos. Ele é deixado para o programador deve verificar se os resultados de uma **static_cast** conversão são seguros.

Esse comportamento também se aplica a tipos diferentes dos tipos de classe. Por exemplo, **static_cast** pode ser usada para converter um int em um **char**. No entanto, o resultante **char** pode não ter bits suficientes para armazenar todo o **int** valor. Novamente, ele é deixado para o programador deve verificar se os resultados de uma **static_cast** conversão são seguros.

O **static_cast** operador também pode ser usado para executar qualquer conversão implícita, incluindo conversões padrão e conversões definidas pelo usuário. Por exemplo:

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

O **static_cast** operador pode converter explicitamente um valor integral para um tipo de enumeração. Se o valor do tipo integral não estiver dentro do intervalo de valores de enumeração, o valor de enumeração resultante será indefinido.

O **static_cast** operador converte um valor de ponteiro nulo para o valor de ponteiro nulo do tipo de destino.

Qualquer expressão pode ser convertido no tipo void pelo explicitamente o **static_cast** operador. O tipo void de destino pode, opcionalmente, incluir a **const**, **volátil**, ou **unaligned** atributo.

O **static_cast** operador não pode eliminar a **const**, **volátil**, ou **unaligned** atributos. Ver [operador const_cast](../cpp/const-cast-operator.md) para obter informações sobre como remover esses atributos.

**C++/CLI:** Devido ao perigo de realizar conversões não verificadas na parte superior de um coletor de lixo realocação, o uso de **static_cast** só deve estar no código crítico de desempenho quando você tiver certeza de que ele funcionará corretamente. Se você precisar usar **static_cast** no modo de liberação, substitua-o por [safe_cast](../extensions/safe-cast-cpp-component-extensions.md) em suas compilações de depuração para garantir o sucesso.

## <a name="see-also"></a>Consulte também

[Operadores de conversão](../cpp/casting-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)