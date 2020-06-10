---
title: Como a impressão padrão é feita
ms.date: 11/04/2016
helpviewer_keywords:
- default printing
- printing [MFC], default
- defaults, printing
ms.assetid: 0f698459-0fc9-4d43-97da-29cf0f65daa2
ms.openlocfilehash: 9ca79ec69037b960e7c455f6ab8abd8833b9a8a0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618580"
---
# <a name="how-default-printing-is-done"></a>Como a impressão padrão é feita

Este artigo explica o processo de impressão padrão no Windows em termos da estrutura do MFC.

Em aplicativos MFC, a classe View tem uma função membro chamada `OnDraw` que contém todo o código de desenho. `OnDraw`usa um ponteiro para um objeto [CDC](reference/cdc-class.md) como um parâmetro. Esse `CDC` objeto representa o contexto do dispositivo para receber a imagem produzida pelo `OnDraw` . Quando a janela que exibe o documento recebe uma mensagem de [WM_PAINT](/windows/win32/gdi/wm-paint) , a estrutura chama `OnDraw` e passa um contexto de dispositivo para a tela (um objeto [CPaintDC](reference/cpaintdc-class.md) , para ser específico). Da mesma `OnDraw` forma, a saída é exibida na tela.

No Programming for Windows, o envio de saída para a impressora é muito semelhante ao envio da saída para a tela. Isso ocorre porque a GDI (interface gráfica do dispositivo) do Windows é independente de hardware. Você pode usar as mesmas funções GDI para exibição de tela ou para impressão simplesmente usando o contexto de dispositivo apropriado. Se o `CDC` objeto que `OnDraw` recebe representa a impressora, a `OnDraw` saída vai para a impressora.

Isso explica como os aplicativos MFC podem executar a impressão simples sem a necessidade de esforço extra de sua parte. A estrutura cuida da exibição da caixa de diálogo Imprimir e da criação de um contexto de dispositivo para a impressora. Quando o usuário seleciona o comando Imprimir no menu arquivo, o modo de exibição passa esse contexto de dispositivo para `OnDraw` , que desenha o documento na impressora.

No entanto, há algumas diferenças significativas entre a exibição da tela e da impressão. Ao imprimir, você precisa dividir o documento em páginas distintas e exibi-los um de cada vez, em vez de exibir qualquer parte visível em uma janela. Como um registro, você precisa estar ciente do tamanho do papel (seja o tamanho da carta, o tamanho legal ou um envelope). Talvez você queira imprimir em orientações diferentes, como o modo paisagem ou retrato. O biblioteca MFC não pode prever como seu aplicativo tratará esses problemas, portanto, ele fornece um protocolo para você adicionar esses recursos.

Esse protocolo é descrito no artigo [documentos com multipágina](multipage-documents.md).

## <a name="see-also"></a>Consulte também

[Impressão](printing.md)
