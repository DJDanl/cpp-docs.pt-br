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
ms.openlocfilehash: a9f90640007f84c854d59cc27e0c38459c76fe46
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619193"
---
# <a name="accessing-run-time-class-information"></a>Acessando informações da classe runtime

Este artigo explica como acessar informações sobre a classe de um objeto em tempo de execução.

> [!NOTE]
> O MFC não usa o suporte de RTTI ( [informações de tipo em tempo de execução](../cpp/run-time-type-information.md) ) introduzido no Visual C++ 4,0.

Se você tiver derivado sua classe de [CObject](reference/cobject-class.md) e usado o **declare**_**Dynamic** e `IMPLEMENT_DYNAMIC` , `DECLARE_DYNCREATE` e `IMPLEMENT_DYNCREATE` , ou as `DECLARE_SERIAL` `IMPLEMENT_SERIAL` macros e explicadas no artigo que [deriva uma classe de CObject](deriving-a-class-from-cobject.md), a `CObject` classe terá a capacidade de determinar a classe exata de um objeto em tempo de execução.

Essa capacidade é mais útil quando a verificação de tipo extra de argumentos de função é necessária e quando você deve escrever código de finalidade especial com base na classe de um objeto. No entanto, essa prática geralmente não é recomendada porque ela duplica a funcionalidade das funções virtuais.

A `CObject` função member `IsKindOf` pode ser usada para determinar se um determinado objeto pertence a uma classe especificada ou se é derivado de uma classe específica. O argumento para `IsKindOf` é um `CRuntimeClass` objeto, que você pode obter usando a `RUNTIME_CLASS` macro com o nome da classe.

### <a name="to-use-the-runtime_class-macro"></a>Para usar a macro RUNTIME_CLASS

1. Use `RUNTIME_CLASS` com o nome da classe, conforme mostrado aqui para a classe `CObject` :

   [!code-cpp[NVC_MFCCObjectSample#4](codesnippet/cpp/accessing-run-time-class-information_1.cpp)]

Você raramente precisará acessar o objeto de classe de tempo de execução diretamente. Um uso mais comum é passar o objeto de classe de tempo de execução para a `IsKindOf` função, conforme mostrado no próximo procedimento. A `IsKindOf` função testa um objeto para ver se ele pertence a uma determinada classe.

#### <a name="to-use-the-iskindof-function"></a>Para usar a função IsKindOf

1. Verifique se a classe tem suporte de classe de tempo de execução. Ou seja, a classe deve ter sido derivada direta ou indiretamente do `CObject` e usado as macros **declare**_**Dynamic** e `IMPLEMENT_DYNAMIC` , `DECLARE_DYNCREATE` and `IMPLEMENT_DYNCREATE` ou, `DECLARE_SERIAL` e `IMPLEMENT_SERIAL` explicadas no artigo que [deriva uma classe de CObject](deriving-a-class-from-cobject.md).

1. Chame a `IsKindOf` função de membro para objetos dessa classe, usando a `RUNTIME_CLASS` macro para gerar o `CRuntimeClass` argumento, como mostrado aqui:

   [!code-cpp[NVC_MFCCObjectSample#2](codesnippet/cpp/accessing-run-time-class-information_2.h)]

   [!code-cpp[NVC_MFCCObjectSample#5](codesnippet/cpp/accessing-run-time-class-information_3.cpp)]

    > [!NOTE]
    >  IsKindOf retornará **true** se o objeto for um membro da classe especificada ou de uma classe derivada da classe especificada. `IsKindOf`o não oferece suporte a várias classes base virtual ou herança, embora você possa usar várias heranças para suas classes derivadas do Microsoft Foundation, se necessário.

Um uso de informações de classe em tempo de execução está na criação dinâmica de objetos. Esse processo é discutido no artigo [criação dinâmica de objeto](dynamic-object-creation.md).

Para obter informações mais detalhadas sobre serialização e informações de classe de tempo de execução, consulte os artigos [arquivos em MFC](files-in-mfc.md) e [serialização](serialization-in-mfc.md).

## <a name="see-also"></a>Consulte também

[Usando CObject](using-cobject.md)
