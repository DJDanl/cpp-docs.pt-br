---
title: Classe Platform::WeakReference
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- Platform::WeakReference
ms.assetid: 8cfe1977-a8c7-4b7b-b539-25c77ed4c5f1
ms.openlocfilehash: befefba7cc76f24f6dddd58d0c5f040bfd205508
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216590"
---
# <a name="platformweakreference-class"></a>Classe Platform::WeakReference

Representa uma referência fraca a uma instância de uma classe ref.

## <a name="syntax"></a>Sintaxe

```cpp
class WeakReference
```

#### <a name="parameters"></a>parâmetros

### <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

|Membro|Descrição|
|------------|-----------------|
|[WeakReference:: WeakReference](#ctor)|Inicializa uma nova instância da classe WeakReference.|

### <a name="methods"></a>Métodos

|Membro|Descrição|
|------------|-----------------|
|[WeakReference:: resolve](#resolve)|Retorna um identificador à classe ref subjacente ou nullptr, caso o objeto não exista mais.|

### <a name="operators"></a>Operadores

|Membro|Descrição|
|------------|-----------------|
|[WeakReference::operator=](#operator-assign)|Atribui um novo valor ao objeto WeakReference.|
|[WeakReference::operator BoolType](#booltype)|Implementa o padrão bool seguro.|

### <a name="remarks"></a>Comentários

A própria classe WeakReference não é uma classe ref e, portanto, não herda de Platform::Object^ e não pode ser usada na assinatura de um método público.

## <a name="weakreferenceoperator"></a><a name="operator-assign"></a>WeakReference:: Operator =

Atribui um valor a WeakReference.

### <a name="syntax"></a>Sintaxe

```cpp
WeakReference& operator=(decltype(__nullptr));
WeakReference& operator=(const WeakReference& otherArg);
WeakReference& operator=(WeakReference&& otherArg);
WeakReference& operator=(const volatile ::Platform::Object^ const otherArg);
```

### <a name="remarks"></a>Comentários

A última sobrecarga na lista acima permite que você atribua uma classe ref a uma variável WeakReference. Nesse caso, a classe ref é downcast para [Platform:: Object](../cppcx/platform-object-class.md)^. Você restaura o tipo original mais tarde, especificando-o como o argumento para o parâmetro de tipo na função de membro [WeakReference:: resolve \<T> ](#resolve) .

## <a name="weakreferenceoperator-booltype"></a><a name="booltype"></a>Bool:: Operator Booliantype

Implementa o padrão de bool seguro para a classe WeakReference. Não deve ser chamada explicitamente em seu código.

### <a name="syntax"></a>Sintaxe

```cpp
BoolType BoolType();
```

## <a name="weakreferenceresolve-method-platform-namespace"></a><a name="resolve"></a>Método WeakReference:: resolve (namespace de plataforma)

Retorna um identificador para a classe ref original ou **`nullptr`** se o objeto não existir mais.

### <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
T^ Resolve() const;
```

### <a name="parameters"></a>parâmetros

### <a name="property-valuereturn-value"></a>Valor da propriedade/Valor do retorno

Um identificador para a classe ref à qual o objeto WeakReference foi associado anteriormente, ou nullptr.

### <a name="example"></a>Exemplo

```cpp
Bar^ bar = ref new Bar();
//use bar...

if (bar != nullptr)
{
    WeakReference wr(bar);
    Bar^ newReference = wr.Resolve<Bar>();
}
```

Observe que o parâmetro de tipo é T, não T^.

## <a name="weakreferenceweakreference-constructor"></a><a name="ctor"></a>Construtor WeakReference:: WeakReference

Fornece várias maneiras de construir um WeakReference.

### <a name="syntax"></a>Sintaxe

```cpp
WeakReference();
WeakReference(decltype(__nullptr));
WeakReference(const WeakReference& otherArg);
WeakReference(WeakReference&& otherArg);
explicit WeakReference(const volatile ::Platform::Object^ const otherArg);
```

### <a name="example"></a>Exemplo

```cpp
MyClass^ mc = ref new MyClass();
WeakReference wr(mc);
MyClass^ copy2 = wr.Resolve<MyClass>();
```

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
