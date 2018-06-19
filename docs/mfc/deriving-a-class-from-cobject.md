---
title: Derivando uma classe de CObject | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- CObject
dev_langs:
- C++
helpviewer_keywords:
- DECLARE_DYNCREATE macro [MFC]
- DECLARE_SERIAL macro [MFC]
- macros [MFC], serialization
- serialization [MFC], macros
- DECLARE_DYNAMIC macro [MFC]
- derived classes [MFC], from CObject
- CObject class [MFC], deriving serializable classes
- CObject class [MFC], deriving from
ms.assetid: 5ea4ea41-08b5-4bd8-b247-c5de8c152a27
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2d0b629617c1592387f3f959996fd3e9837242ea
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33349351"
---
# <a name="deriving-a-class-from-cobject"></a>Derivando uma classe de CObject
Este artigo descreve as etapas mínimas necessárias para derivar uma classe de [CObject](../mfc/reference/cobject-class.md). Outros `CObject` artigos de classe descrevem as etapas necessárias para tirar proveito de específicos `CObject` recursos, como a serialização e suporte de depuração de diagnóstico.  
  
 Em discussões de `CObject`, os termos "arquivo de interface" e "arquivo de implementação" são usados com frequência. O arquivo de interface (geralmente chamado de arquivo de cabeçalho, ou. Arquivo H) contém a declaração de classe e quaisquer outras informações necessárias para usar a classe. O arquivo de implementação (ou). O arquivo CPP) contém a definição de classe, bem como o código que implementa as funções de membro de classe. Por exemplo, para uma classe denominada `CPerson`, normalmente você criaria um arquivo de interface chamado pessoa. H e um arquivo de implementação chamado pessoa. CPP. No entanto, para algumas classes de pequenos que não serão compartilhados entre aplicativos, às vezes é mais fácil combinar a interface e a implementação em um único. Arquivo CPP.  
  
 Você pode escolher entre quatro níveis de funcionalidade ao derivar uma classe de `CObject`:  
  
-   Funcionalidade básica: não há suporte para serialização ou informações de classe de tempo de execução mas não inclui gerenciamento de diagnóstico de memória.  
  
-   Funcionalidade básica, além de suporte para obter informações de classe de tempo de execução.  
  
-   Funcionalidade básica, além de suporte para obter informações de classe de tempo de execução e criação dinâmica.  
  
-   Funcionalidade básica, além de suporte para serialização, criação dinâmica e informações de classe de tempo de execução.  
  
 Classes criada para reutilização (aquelas que servirá como classes base mais tarde) devem incluir pelo menos o suporte da classe de tempo de execução e suporte de serialização, se todas as necessidades futuras de serialização é prevista.  
  
 Escolha o nível de funcionalidade usando macros de declaração e a implementação específicas na declaração e implementação das classes que derivam de `CObject`.  
  
 A tabela a seguir mostra a relação entre as macros usado para suporte à serialização e informações de tempo de execução.  
  
### <a name="macros-used-for-serialization-and-run-time-information"></a>Usado para serialização e informações de tempo de execução de macros  
  
|Macro usada|CObject::IsKindOf|CRuntimeClass::<br /><br /> CreateObject|CArchive::operator >><br /><br /> CArchive::operator <<|  
|----------------|-----------------------|--------------------------------------|-------------------------------------------------------|  
|Básico `CObject` funcionalidade|Não|Não|Não|  
|`DECLARE_DYNAMIC`|Sim|Não|Não|  
|`DECLARE_DYNCREATE`|Sim|Sim|Não|  
|`DECLARE_SERIAL`|Sim|Sim|Sim|  
  
#### <a name="to-use-basic-cobject-functionality"></a>Para usar a funcionalidade básica de CObject  
  
1.  Use a sintaxe de C++ normal para derivar a classe de `CObject` (ou de uma classe derivada de `CObject`).  
  
     O exemplo a seguir mostra o caso mais simples, a derivação de uma classe de `CObject`:  
  
     [!code-cpp[NVC_MFCCObjectSample#1](../mfc/codesnippet/cpp/deriving-a-class-from-cobject_1.h)]  
  
 Normalmente, no entanto, você talvez queira substituir alguns `CObject`de funções de membro para lidar com as especificações da nova classe. Por exemplo, geralmente convém substituir o `Dump` função de `CObject` para fornecer a saída de depuração para o conteúdo da sua classe. Para obter detalhes sobre como substituir `Dump`, consulte o artigo [diagnóstico: despejo de conteúdo do objeto](http://msdn.microsoft.com/en-us/727855b1-5a83-44bd-9fe3-f1d535584b59). Talvez você queira substituir o `AssertValid` função de `CObject` para fornecer teste personalizado para validar a consistência dos membros de dados de objetos de classe. Para obter uma descrição de como substituir `AssertValid`, consulte [MFC ASSERT_VALID e CObject::AssertValid](http://msdn.microsoft.com/en-us/7654fb75-9e9a-499a-8165-0a96faf2d5e6).  
  
 O artigo [especificando níveis de funcionalidade](../mfc/specifying-levels-of-functionality.md) descreve como especificar outros níveis de funcionalidade, incluindo informações de classe de tempo de execução, a criação de objeto dinâmico e a serialização.  
  
## <a name="see-also"></a>Consulte também  
 [Usando CObject](../mfc/using-cobject.md)

