---
title: '&lt;see&gt; (Visual C++)'
ms.date: 11/04/2016
f1_keywords:
- <see>
- see
helpviewer_keywords:
- <see> C++ XML tag
- see C++ XML tag
ms.assetid: 20ef66f4-b278-45cf-8613-63919edf5720
ms.openlocfilehash: c8e797dff1495e9b4573ab4e0820d60b8027a293
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57747586"
---
# <a name="ltseegt-visual-c"></a>&lt;see&gt; (Visual C++)

Use a marca \<see> para especificar um link de dentro do texto. Use [\<seealso>](../ide/seealso-visual-cpp.md) para indicar o texto que você deseja exibir em uma seção Confira também.

## <a name="syntax"></a>Sintaxe

```
<see cref="member"/>
```

#### <a name="parameters"></a>Parâmetros

*member*<br/>
Uma referência a um membro ou campo disponível para ser chamado do ambiente de compilação atual.  Coloque o nome entre aspas simples ou duplas.

O compilador verifica se o elemento de código fornecido existe e resolve `member` no nome de elemento no XML de saída.  O compilador emite um aviso se não encontra `member`.

## <a name="remarks"></a>Comentários

Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

Confira [\<summary>](../ide/summary-visual-cpp.md) para obter um exemplo de como usar \<see>.

O compilador do Visual C++ tentará resolver as referências cref em uma passagem pelos comentários da documentação.  Portanto, se você estiver usando as regras de pesquisa do C++ e um símbolo não for encontrado pelo compilador, a referência será marcada como não resolvida. Confira [\<seealso>](../ide/seealso-visual-cpp.md) para obter mais informações.

## <a name="example"></a>Exemplo

A amostra a seguir explica como você pode fazer uma referência cref a um tipo genérico, de modo que o compilador resolva a referência.

```
// xml_see_cref_example.cpp
// compile with: /LD /clr /doc
// the following cref shows how to specify the reference, such that,
// the compiler will resolve the reference
/// <see cref="C{T}">
/// </see>
ref class A {};

// the following cref shows another way to specify the reference,
// such that, the compiler will resolve the reference
/// <see cref="C < T >"/>

// the following cref shows how to hard-code the reference
/// <see cref="T:C`1">
/// </see>
ref class B {};

/// <see cref="A">
/// </see>
/// <typeparam name="T"></typeparam>
generic<class T>
ref class C {};
```

## <a name="see-also"></a>Consulte também

[Documentação XML](../ide/xml-documentation-visual-cpp.md)
