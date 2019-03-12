---
title: '&lt;seealso&gt; (Visual C++)'
ms.date: 11/04/2016
f1_keywords:
- <seealso>
- seealso
helpviewer_keywords:
- seealso C++ XML tag
- <seealso> C++ XML tag
ms.assetid: cb33d100-9c50-4485-8d0c-573429eff155
ms.openlocfilehash: 184ea874311c50caaa60440ea4f22fe40f240a6e
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57746156"
---
# <a name="ltseealsogt-visual-c"></a>&lt;seealso&gt; (Visual C++)

A marca \<seealso > permite especificar o texto que você quer que seja exibido na seção Ver também. Use [\<see>](../ide/see-visual-cpp.md) para especificar um link de dentro do texto.

## <a name="syntax"></a>Sintaxe

```
<seealso cref="member"/>
```

#### <a name="parameters"></a>Parâmetros

*member*<br/>
Uma referência a um membro ou campo disponível para ser chamado do ambiente de compilação atual.  Coloque o nome entre aspas simples ou duplas.

O compilador verifica se o elemento de código fornecido existe e resolve `member` no nome de elemento no XML de saída.  O compilador emite um aviso se não encontra `member`.

Para obter informações sobre como criar uma referência cref para um tipo genérico, consulte [ \<consulte>](../ide/see-visual-cpp.md).

## <a name="remarks"></a>Comentários

Compile com [/doc](../build/reference/doc-process-documentation-comments-c-cpp.md) para processar comentários de documentação em um arquivo.

Consulte [\<summary>](../ide/summary-visual-cpp.md) para obter um exemplo sobre o uso de \<seealso>.

O compilador do Visual C++ tentará resolver as referências cref em uma passagem pelos comentários da documentação.  Portanto, se você estiver usando as regras de pesquisa do C++ e um símbolo não for encontrado pelo compilador, a referência será marcada como não resolvida.

## <a name="example"></a>Exemplo

Na amostra a seguir, um símbolo não resolvido é referenciado em um cref. O comentário XML do cref para B::Test será `<seealso cref="!:B::Test" />`, enquanto a referência a A::Test é um `<seealso cref="M:A.Test" />` bem formado.

```
// xml_seealso_tag.cpp
// compile with: /LD /clr /doc
// post-build command: xdcmake xml_seealso_tag.dll

/// Text for class A.
public ref struct A {
   /// <summary><seealso cref="A::Test"/>
   /// <seealso cref="B::Test"/>
   /// </summary>
   void MyMethod(int Int1) {}

   /// text
   void Test() {}
};

/// Text for class B.
public ref struct B {
   void Test() {}
};
```

## <a name="see-also"></a>Consulte também

[Documentação XML](../ide/xml-documentation-visual-cpp.md)
