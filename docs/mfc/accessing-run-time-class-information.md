---
title: Acessando informações da classe runtime
ms.date: 11/04/2016
helpviewer_keywords:
- CObject class [MFC], and RTTI
- CObject class [MFC], using IsKindOf method [MFC]
- run time [MFC], class information
- RUNTIME_CLASS macro [MFC]
- CObject class [MFC], using RUNTIME_CLASS macro [MFC]
- RTTI compiler option [MFC]
- CObject class [MFC], accessing run-time class information
- run time [MFC]
- IsKindOf method method [MFC]
- run-time class [MFC], accessing information
- classes [MFC], run-time class information
- run-time class [MFC]
- RUNTIME_CLASS macro, using
ms.assetid: 3445a9af-0bd6-4496-95c3-aa59b964570b
ms.openlocfilehash: 4a836bb7bd03bd6654e5c940442fecf541042fd1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354220"
---
# <a name="accessing-run-time-class-information"></a>Acessando informações da classe runtime

Este artigo explica como acessar informações sobre a classe de um objeto em tempo de execução.

> [!NOTE]
> O MFC não usa o suporte RTTI [(Run-Time Type Information)](../cpp/run-time-type-information.md) introduzido no Visual C++ 4.0.

Se você tiver derivado sua classe do [CObject](../mfc/reference/cobject-class.md) e `DECLARE_DYNCREATE` usado `IMPLEMENT_DYNCREATE`o `DECLARE_SERIAL` **DECLARE**_**DYNAMIC** `IMPLEMENT_DYNAMIC`e , o e , e `CObject` e `IMPLEMENT_SERIAL` as macros explicadas no artigo [Derivando uma Classe de CObject,](../mfc/deriving-a-class-from-cobject.md)a classe tem a capacidade de determinar a classe exata de um objeto no tempo de execução.

Essa habilidade é mais útil quando é necessária uma verificação de tipo extra dos argumentos de função e quando você deve escrever código de propósito especial com base na classe de um objeto. No entanto, essa prática não costuma ser recomendada porque duplica a funcionalidade das funções virtuais.

A `CObject` função `IsKindOf` membro pode ser usada para determinar se um objeto específico pertence a uma classe especificada ou se é derivado de uma classe específica. O argumento `IsKindOf` para `CRuntimeClass` é um objeto, `RUNTIME_CLASS` que você pode obter usando a macro com o nome da classe.

### <a name="to-use-the-runtime_class-macro"></a>Para usar a RUNTIME_CLASS macro

1. Use `RUNTIME_CLASS` com o nome da classe, como `CObject`mostrado aqui para a classe :

   [!code-cpp[NVC_MFCCObjectSample#4](../mfc/codesnippet/cpp/accessing-run-time-class-information_1.cpp)]

Você raramente precisará acessar o objeto de classe de tempo de execução diretamente. Um uso mais comum é passar o `IsKindOf` objeto de classe de tempo de execução para a função, como mostrado no procedimento seguinte. A `IsKindOf` função testa um objeto para ver se pertence a uma classe específica.

#### <a name="to-use-the-iskindof-function"></a>Para usar a função IsKindOf

1. Certifique-se de que a classe tenha suporte de classe em tempo de execução. Ou seja, a classe deve ter sido `CObject` derivada direta ou `IMPLEMENT_DYNAMIC`indiretamente `DECLARE_DYNCREATE` `IMPLEMENT_DYNCREATE`e usado `DECLARE_SERIAL` `IMPLEMENT_SERIAL` o **DECLARE**_**DYNAMIC** e , o e , ou as e e macros explicadas no artigo [Derivando uma Classe de CObject](../mfc/deriving-a-class-from-cobject.md).

1. Chame `IsKindOf` a função de membro para `RUNTIME_CLASS` objetos dessa `CRuntimeClass` classe, usando a macro para gerar o argumento, como mostrado aqui:

   [!code-cpp[NVC_MFCCObjectSample#2](../mfc/codesnippet/cpp/accessing-run-time-class-information_2.h)]

   [!code-cpp[NVC_MFCCObjectSample#5](../mfc/codesnippet/cpp/accessing-run-time-class-information_3.cpp)]

    > [!NOTE]
    >  IsKindOf retorna **TRUE** se o objeto for um membro da classe especificada ou de uma classe derivada da classe especificada. `IsKindOf`não suporta várias classes de herança ou base virtual, embora você possa usar várias heranças para suas classes derivadas da Microsoft Foundation, se necessário.

Um uso de informações de classe de tempo de execução está na criação dinâmica de objetos. Esse processo é discutido no artigo [Criação dinâmica de objetos](../mfc/dynamic-object-creation.md).

Para obter informações mais detalhadas sobre serialização e informações de classe de tempo de execução, consulte os artigos [Arquivos em MFC](../mfc/files-in-mfc.md) e [Serialização](../mfc/serialization-in-mfc.md).

## <a name="see-also"></a>Confira também

[Usando CObject](../mfc/using-cobject.md)
