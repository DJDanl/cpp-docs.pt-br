---
title: Como a impressão padrão é feita | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- default printing
- printing [MFC], default
- defaults, printing
ms.assetid: 0f698459-0fc9-4d43-97da-29cf0f65daa2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 90f6559459bed9376dba8b7d9059761e9ace5ac8
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43202824"
---
# <a name="how-default-printing-is-done"></a>Como a impressão padrão é feita
Este artigo explica o processo de impressão padrão no Windows em termos de estrutura MFC.  
  
 Em aplicativos MFC, a classe de exibição tem uma função de membro chamada `OnDraw` que contém todo o código de desenho. `OnDraw` usa um ponteiro para um [CDC](../mfc/reference/cdc-class.md) objeto como um parâmetro. Que `CDC` objeto representa o contexto de dispositivo para receber a imagem produzida por `OnDraw`. Quando a janela de exibição de documento recebe um [WM_PAINT](/windows/desktop/gdi/wm-paint) da mensagem, a estrutura chama `OnDraw` e o transmite um contexto de dispositivo para a tela (um [CPaintDC](../mfc/reference/cpaintdc-class.md) objeto para ser específico). Da mesma forma, `OnDraw`saída vai para a tela.  
  
 Na programação para Windows, envia saída para a impressora é muito semelhante ao envio de saída para a tela. Isso ocorre porque a graphics device interface (GDI) da Windows é independente de hardware. Você pode usar as mesmas funções GDI para a exibição de tela ou para impressão usando o contexto de dispositivo apropriados. Se o `CDC` do objeto `OnDraw` recebe representa a impressora `OnDraw`saída vai para a impressora.  
  
 Isso explica como aplicativos MFC podem executar a impressão simple sem a necessidade de um esforço extra de sua parte. A estrutura se encarrega de exibir a caixa de diálogo de impressão e criando um contexto de dispositivo para a impressora. Quando o usuário seleciona o comando Imprimir no menu Arquivo, o modo de exibição passa esse contexto de dispositivo `OnDraw`, que desenha o documento na impressora.  
  
 No entanto, há algumas diferenças significativas entre impressão e exibição de tela. Quando você imprime, você precisa dividir o documento em páginas distintas e -las uma por vez, em vez de exibir qualquer parte é visível em uma janela de exibição. Como consequência, você precisa estar ciente do tamanho do papel (seja tamanho carta, Ofício ou um envelope). Você talvez queira imprimir em diferentes orientações, como o modo de paisagem ou retrato. A biblioteca Microsoft Foundation Class não pode prever como o seu aplicativo manipulará esses problemas, portanto, ele fornece um protocolo para adicionar esses recursos.  
  
 Se o protocolo é descrito no artigo [Multipage documentos](../mfc/multipage-documents.md).  
  
## <a name="see-also"></a>Consulte também  
 [Imprimindo](../mfc/printing.md)

