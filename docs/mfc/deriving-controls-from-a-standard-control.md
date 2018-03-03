---
title: "Derivando controles a partir de um controle padrão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- standard controls [MFC], deriving controls from
- common controls [MFC], deriving from
- derived controls
- controls [MFC], derived
- Windows common controls [MFC], deriving from
- standard controls
ms.assetid: a6f84315-7007-4e0e-8576-78be81254802
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2b93bc07fc5ab4680caaa276daaeca86189b8ce5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="deriving-controls-from-a-standard-control"></a>Derivando controles a partir de um controle padrão
Assim como acontece com qualquer [CWnd](../mfc/reference/cwnd-class.md)-derivado da classe, você pode modificar o comportamento de um controle pelo derivar uma nova classe de uma classe de controle existente.  
  
### <a name="to-create-a-derived-control-class"></a>Para criar uma classe derivada de controle  
  
1.  Derive sua classe de uma classe de controle existente e, opcionalmente, substituir o **criar** para que ele forneça os argumentos necessários para a classe de base de função de membro **criar** função.  
  
2.  Fornece funções de membro de manipulador de mensagens e entradas de mapa de mensagem para modificar o comportamento do controle em resposta a mensagens específicas do Windows. Consulte [mapeando mensagens para funções](../mfc/reference/mapping-messages-to-functions.md).  
  
3.  Fornece novas funções de membro para estender a funcionalidade do controle (opcional).  
  
 Usando um controle derivado em uma caixa de diálogo requer trabalho adicional. Os tipos e as posições de controles em uma caixa de diálogo normalmente são especificadas em um recurso de modelo de caixa de diálogo. Se você criar uma classe derivada de controle, você não pode especificá-lo em um modelo de caixa de diálogo, desde que o compilador de recurso não sabe nada sobre sua classe derivada.  
  
#### <a name="to-place-your-derived-control-in-a-dialog-box"></a>Para posicionar o controle derivada em uma caixa de diálogo  
  
1.  Inserir um objeto da classe derivada de controle na declaração da classe derivada da caixa de diálogo.  
  
2.  Substituir o `OnInitDialog` a função de membro em sua classe de caixa de diálogo para chamar o `SubclassDlgItem` a função de membro para o controle derivado.  
  
 `SubclassDlgItem`"dinamicamente subclasses" um controle criada de um modelo de caixa de diálogo. Quando um controle dinamicamente em uma subclasse, conectar-se no Windows, algumas mensagens são processados em seu próprio aplicativo e passar mensagens restantes no Windows. Para obter mais informações, consulte o [SubclassDlgItem](../mfc/reference/cwnd-class.md#subclassdlgitem) função de membro de classe `CWnd` no *referência MFC*. O exemplo a seguir mostra como você pode escrever uma substituição de `OnInitDialog` chamar `SubclassDlgItem`:  
  
 [!code-cpp[NVC_MFCControlLadenDialog#3](../mfc/codesnippet/cpp/deriving-controls-from-a-standard-control_1.cpp)]  
  
 Como o controle derivado é incorporado na classe de caixa de diálogo, ele será construído quando a caixa de diálogo é construída e serão destruído quando a caixa de diálogo é destruída. Compare o código de exemplo do [adicionando mão de By controles](../mfc/adding-controls-by-hand.md).  
  
## <a name="see-also"></a>Consulte também  
 [Criando e usando controles](../mfc/making-and-using-controls.md)   
 [Controles](../mfc/controls-mfc.md)

