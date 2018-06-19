---
title: Desenhando uma exibição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- drawing [MFC], in views
- views [MFC], printing
- views [MFC], updating
- printing [MFC], views
- views [MFC], rendering
- printing views [MFC]
- paint messages in view class [MFC]
- device contexts, screen drawings
ms.assetid: e3761db6-0f19-4482-a4cd-ac38ef7c4d3a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bc716800c35aa922f7912f586d6e5b8429593615
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33346159"
---
# <a name="drawing-in-a-view"></a>Desenhando uma exibição
Desenhando quase todos em seu aplicativo ocorre no modo de exibição `OnDraw` função de membro, você deve substituir em sua classe de exibição. (A exceção é mouse desenho, discutido em [Interpretando entrada por meio de uma exibição de usuário](../mfc/interpreting-user-input-through-a-view.md).) O `OnDraw` substituir:  
  
1.  Obtém dados chamando funções de membro que você fornecer o documento.  
  
2.  Exibe os dados chamando funções de membro de um objeto de contexto de dispositivo que passa a estrutura para `OnDraw`.  
  
 Quando dados do documento é alterado de alguma forma, o modo de exibição deve ser redesenhado para refletir as alterações. Normalmente, isso ocorre quando o usuário faz uma alteração por meio de uma exibição no documento. Nesse caso, o modo de exibição chama o documento [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) a função de membro para notificar todos os modos de exibição no documento para atualizar a si mesmo. `UpdateAllViews` chama cada exibição [OnUpdate](../mfc/reference/cview-class.md#onupdate) função de membro. A implementação padrão de `OnUpdate` invalida a área de cliente inteiro do modo de exibição. Você pode substituí-la para invalidar apenas essas regiões da área do cliente que são mapeados para as partes de modificação do documento.  
  
 O `UpdateAllViews` função de membro de classe **CDocument** e `OnUpdate` função de membro de classe `CView` permitem que você transmite informações que descrevem quais partes do documento foram modificadas. Esse mecanismo de "dica" permite limitar a área que deve redesenhar a exibição. `OnUpdate` leva dois argumentos de "dica". A primeira, `lHint`, do tipo **LPARAM**, permite que você transmitir os dados que desejar, enquanto o segundo, `pHint`, do tipo `CObject`*, permite que você transmitir um ponteiro para qualquer objeto derivado de `CObject`.  
  
 Quando uma exibição se torna inválida, o Windows envia a ele um `WM_PAINT` mensagem. O modo de exibição [OnPaint](../mfc/reference/cwnd-class.md#onpaint) função do manipulador responde à mensagem com a criação de um objeto de contexto de dispositivo da classe [CPaintDC](../mfc/reference/cpaintdc-class.md) e chama o modo de exibição `OnDraw` função de membro. Normalmente não é necessário gravar um substituindo `OnPaint` função do manipulador.  
  
 Um [contexto de dispositivo](../mfc/device-contexts.md) é uma estrutura de dados do Windows que contém informações sobre os atributos de desenho de um dispositivo, como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo. Para desenhar na tela, `OnDraw` é passado um `CPaintDC` objeto. Para desenhar em uma impressora, ele é passado um [CDC](../mfc/reference/cdc-class.md) configurado para a impressora atual do objeto.  
  
 Primeiro, seu código para desenho no modo de exibição recupera um ponteiro para o documento e faz chamadas de desenho por meio do contexto de dispositivo. A seguir simples `OnDraw` exemplo ilustra o processo:  
  
 [!code-cpp[NVC_MFCDocView#1](../mfc/codesnippet/cpp/drawing-in-a-view_1.cpp)]  
  
 Neste exemplo, você deve definir o `GetData` funcionar como um membro da sua classe derivada de documento.  
  
 O exemplo imprime qualquer cadeia de caracteres que ele obtém do documento, centralizado na exibição. Se o `OnDraw` é chamada de desenho da tela, o `CDC` objeto transmitido `pDC` é um `CPaintDC` cujo construtor já chamado `BeginPaint`. Chamadas a funções de desenho são feitas através do ponteiro de contexto de dispositivo. Para obter informações sobre os contextos de dispositivo e chamadas de desenho, consulte a classe [CDC](../mfc/reference/cdc-class.md) no *referência MFC* e [trabalhando com objetos de janela](../mfc/working-with-window-objects.md).  
  
 Para obter mais exemplos de como escrever `OnDraw`, consulte o [amostras MFC](../visual-cpp-samples.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando exibições](../mfc/using-views.md)

