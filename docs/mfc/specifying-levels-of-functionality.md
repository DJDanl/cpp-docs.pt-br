---
title: Especificando níveis de funcionalidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CObject class [MFC], adding functionality to derived classes
- runtime [MFC], class information
- serialization [MFC], Cobject
- dynamic creation support
- levels [MFC], functionality in CObject
- run-time class [MFC], information support
- levels [MFC]
ms.assetid: 562669ba-c858-4f66-b5f1-b3beeea4f486
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f32b9502d2e8bd1c1483d817b759ca204f5c9c1a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="specifying-levels-of-functionality"></a>Especificando níveis de funcionalidade
Este artigo descreve como adicionar os seguintes níveis de funcionalidade ao seu [CObject](../mfc/reference/cobject-class.md)-classe derivada:  
  
-   [Informações de classe de tempo de execução](#_core_to_add_run.2d.time_class_information)  
  
-   [Suporte à criação dinâmica](#_core_to_add_dynamic_creation_support)  
  
-   [Suporte de serialização](#_core_to_add_serialization_support)  
  
 Para obter uma descrição geral de `CObject` funcionalidade, consulte o artigo [derivando uma classe de CObject](../mfc/deriving-a-class-from-cobject.md).  
  
-   [Informações de classe de tempo de execução](#_core_to_add_run.2d.time_class_information)  
#### <a name="_core_to_add_run.2d.time_class_information"></a> Para adicionar informações de classe de tempo de execução  
  
1.  Derive a classe de `CObject`, conforme descrito no [derivando uma classe de CObject](../mfc/deriving-a-class-from-cobject.md) artigo.  
  
2.  Use o `DECLARE_DYNAMIC` macro na sua declaração de classe, conforme mostrado aqui:  
  
     [!code-cpp[NVC_MFCCObjectSample#2](../mfc/codesnippet/cpp/specifying-levels-of-functionality_1.h)]  
  
3.  Use o `IMPLEMENT_DYNAMIC` macro no arquivo de implementação (. CPP) da sua classe. Esta macro usa como argumentos o nome da classe e sua classe base, da seguinte maneira:  
  
     [!code-cpp[NVC_MFCCObjectSample#3](../mfc/codesnippet/cpp/specifying-levels-of-functionality_2.cpp)]  
  
> [!NOTE]
>  Sempre colocar `IMPLEMENT_DYNAMIC` no arquivo de implementação (. CPP) para a sua classe. O `IMPLEMENT_DYNAMIC` macro deve ser avaliada apenas uma vez durante uma compilação e, portanto, não deve ser usada em um arquivo de interface (. H) que potencialmente pode ser incluído em mais de um arquivo.  
  
#### <a name="_core_to_add_dynamic_creation_support"></a> Para adicionar suporte à criação dinâmica  
  
1.  Derive a classe de `CObject`.  
  
2.  Use o `DECLARE_DYNCREATE` macro na declaração da classe.  
  
3.  Defina um construtor sem argumentos (um construtor padrão).  
  
4.  Use o `IMPLEMENT_DYNCREATE` macro no arquivo de implementação da classe.  
  
#### <a name="_core_to_add_serialization_support"></a> Para adicionar suporte de serialização  
  
1.  Derive a classe de `CObject`.  
  
2.  Substituir o `Serialize` função de membro.  
  
    > [!NOTE]
    >  Se você chamar `Serialize` diretamente, ou seja, você não deseja serializar o objeto por meio de um ponteiro polimórfico, omita as etapas 3 a 5.  
  
3.  Use o `DECLARE_SERIAL` macro na declaração da classe.  
  
4.  Defina um construtor sem argumentos (um construtor padrão).  
  
5.  Use o `IMPLEMENT_SERIAL` macro no arquivo de implementação da classe.  
  
> [!NOTE]
>  Um "ponteiro polimórfico" aponta para um objeto de uma classe (chamá-lo um) ou a um objeto de qualquer classe derivada de um (digamos, B). Para serializar através de um ponteiro polimórfico, a estrutura deve determinar a classe de tempo de execução do objeto que ele é serializar (B), como ele pode ser um objeto de qualquer classe derivada de uma classe base (A).  
  
 Para obter mais detalhes sobre como habilitar a serialização, derive sua classe da `CObject`, consulte os artigos [arquivos no MFC](../mfc/files-in-mfc.md) e [serialização](../mfc/serialization-in-mfc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Derivando uma classe de CObject](../mfc/deriving-a-class-from-cobject.md)
