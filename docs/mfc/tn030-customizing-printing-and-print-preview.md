---
title: "TN030: Personalizando impressão e visualização de impressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.print
dev_langs:
- C++
helpviewer_keywords:
- TN030
- customizing printing and print preview
- printing [MFC], views
- printing views [MFC]
- print preview [MFC], customizing
ms.assetid: 32744697-c91c-41b6-9a12-b8ec01e0d438
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: aa11c30fb41630a5b293698fe3e69a80509f3f2f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="tn030-customizing-printing-and-print-preview"></a>TN030: personalizando impressão e visualização de impressão
> [!NOTE]
>  A Observação técnica a seguir não foi atualizada desde que ele foi incluído primeiro na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação on-line.  
  
 Esta anotação descreve o processo de personalização de impressão e visualização de impressão e descreve as finalidades das rotinas de retorno de chamada usadas em `CView` e as rotinas de retorno de chamada e a funções de membro **CPreviewView**.  
  
## <a name="the-problem"></a>O problema  
 MFC fornece uma solução completa para a maioria dos impressão e visualização de impressão precisa. Na maioria dos casos, pouco código adicional é necessário ter uma exibição capaz de impressão e visualização. No entanto, há maneiras de otimizar a impressão que exigem um esforço significativo por parte do desenvolvedor, e alguns aplicativos precisam adicionar elementos da interface do usuário específico para o modo de visualização de impressão.  
  
## <a name="efficient-printing"></a>Impressão eficiente  
 Quando um aplicativo MFC será impressa usando os métodos padrão, o Windows direciona todas as chamadas de saída de Interface gráfica de dispositivo (GDI) para um metarquivo na memória. Quando `EndPage` é chamado, o Windows desempenha o metarquivo uma vez para cada faixa físico que requer que a impressora para imprimir uma página. Durante esse processamento GDI frequentemente consulta o procedimento anular para determinar se deve continuar. Normalmente, o procedimento de anulação permite que mensagens a serem processadas para que o usuário pode anular o trabalho de impressão usando uma caixa de diálogo de impressão.  
  
 Infelizmente, isso pode reduzir o processo de impressão. Se a impressão em seu aplicativo deve ser mais rápida do que pode ser obtida usando a técnica padrão, você deve implementar faixas manual.  
  
## <a name="print-banding"></a>Imprimir faixas  
 Para banda manualmente, você deve re implementar o loop de impressão, de modo que `OnPrint` for chamado várias vezes por página (uma vez por faixa). O loop de impressão é implementado no **OnFilePrint** função em viewprnt.cpp. No seu `CView`-derivado da classe, sobrecarregar esta função para que a entrada de mapa de mensagem para lidar com o comando print chama sua função de impressão. Copie o **OnFilePrint** de rotina e o loop de impressão para implementar a faixas de alteração. Você provavelmente também deseja transmitir o retângulo de faixa para funções de impressão que você pode otimizar o desenho com base na seção da página seja impressa.  
  
 Em segundo lugar, você deve chamar frequentemente `QueryAbort` durante o desenho da faixa. Caso contrário, o procedimento de anulação não será chamado e o usuário poderá cancelar o trabalho de impressão.  
  
## <a name="print-preview-electronic-paper-with-user-interface"></a>Visualização de impressão: O papel eletrônico com Interface de usuário  
 Visualizar impressão, em essência, tenta ativar a exibição em uma emulação de uma impressora. Por padrão, a área de cliente da janela principal é usada para exibir uma ou duas páginas completamente dentro da janela. O usuário é capaz de aumentar o zoom em uma área da página para ver com mais detalhes. Com suporte adicional, o usuário ainda poderá ter permissão para editá-lo no modo de visualização.  
  
## <a name="customizing-print-preview"></a>Personalizando a visualização de impressão  
 Esta anotação lida apenas com um aspecto da modificação de visualização de impressão: adicionando a interface de usuário para o modo de visualização. Outras modificações são possíveis, mas tais alterações estão fora do escopo desta discussão.  
  
## <a name="to-add-ui-to-the-preview-mode"></a>Para adicionar a interface do usuário para o modo de visualização  
  
1.  Derive uma classe de exibição de **CPreviewView**.  
  
2.  Adicione manipuladores de comandos para os aspectos da interface do usuário desejado.  
  
3.  Se você estiver adicionando aspectos visuais para exibição, substitua `OnDraw` e executar o desenho depois de chamar **CPreviewView::OnDraw.**  
  
## <a name="onfileprintpreview"></a>OnFilePrintPreview  
 Isso é o manipulador de comando para a visualização de impressão. Sua implementação do padrão é:  
  
```  
void CView::OnFilePrintPreview()  
{ *// In derived classes,
    implement special window handling here *// Be sure to Unhook Frame Window close if hooked.  
 *// must not create this on the frame. Must outlive this function  
    CPrintPreviewState* pState = new CPrintPreviewState;  
 
    if (!DoPrintPreview(AFX_IDD_PREVIEW_TOOLBAR,
    this,  
    RUNTIME_CLASS(CPreviewView),
    pState))  
 { *// In derived classes,
    reverse special window handling *// here for Preview failure case  
 
    TRACE0("Error: DoPrintPreview failed");

    AfxMessageBox(AFX_IDP_COMMAND_FAILURE);

 delete pState;      // preview failed to initialize, *// delete State now  
 }  
}  
```  
  
 **DoPrintPreview** ocultará o painel principal do aplicativo. Barras de controle, como a barra de status, podem ser mantidas especificando-os no pState ->**dwStates** membro (Esta é uma máscara de bits e os bits das barras de controle individual são definidos pelos **AFX_CONTROLBAR_MASK**(AFX_IDW_MYBAR)). A janela pState ->**nIDMainPane** é a janela que serão automaticamente ocultada e reshown. **DoPrintPreview** , em seguida, criará uma barra de botões para a interface do usuário visualização padrão. Se for necessário tratamento especial de janela, por exemplo, para ocultar ou mostrar outras janelas, que devem ser feitas antes de **DoPrintPreview** é chamado.  
  
 Por padrão, quando termina de visualização de impressão, ele retorna as barras de controle para seus estados originais e o painel principal para visível. Se for necessário um tratamento especial, isso deve ser feito em uma substituição de **EndPrintPreview.** Se **DoPrintPreview** falhar, também fornecem um tratamento especial.  
  
 DoPrintPreview é chamado com:  
  
-   A ID de recurso do modelo de caixa de diálogo para a barra de ferramentas de visualização.  
  
-   Um ponteiro para o modo de exibição para executar a impressão para a visualização de impressão.  
  
-   A classe de tempo de execução da classe de visualização. Isso será criado dinamicamente em DoPrintPreview.  
  
-   O ponteiro CPrintPreviewState. Observe que a estrutura de CPrintPreviewState (ou a estrutura derivada se o aplicativo precisar de mais de estado preservado) deve *não* ser criado no quadro. DoPrintPreview é sem janela restrita e essa estrutura deve sobreviver até EndPrintPreview é chamado.  
  
    > [!NOTE]
    >  Se uma classe de exibição ou exibição separada é necessário para suporte de impressão, um ponteiro para o objeto deve ser passado como o segundo parâmetro.  
  
## <a name="endprintpreview"></a>EndPrintPreview  
 Isso é chamado para encerrar o modo de visualização de impressão. Geralmente é desejável para passar para a página do documento última exibida na visualização de impressão. **EndPrintPreview** possibilidade do aplicativo para fazer isso. O pInfo ->`m_nCurPage` membro é a página exibida último (mais à esquerda se duas páginas foram exibidas) e o ponteiro é uma dica sobre onde na página do usuário estava interessado. Como a estrutura do modo de exibição do aplicativo é desconhecida para a estrutura, você deve fornecer o código para mover para o ponto de escolhida.  
  
 Você deve executar a maioria das ações antes de chamar **CView::EndPrintPreview**. Essa chamada inverte os efeitos de **DoPrintPreview** e exclui pView pDC e pInfo.  
  
```  
// Any further cleanup should be done here.  
CView::EndPrintPreview(pDC,
    pInfo,
    point,
    pView);
```  
  
## <a name="cwinapponfileprintsetup"></a>CWinApp::OnFilePrintSetup  
 Isso deve ser mapeado para o item de menu Configurar impressão. Na maioria dos casos, não é necessário substituir a implementação.  
  
## <a name="page-nomenclature"></a>Nomenclatura de página  
 Outro problema é que a numeração de página e a ordem. Para aplicativos de tipo de processador de texto simples, esse é um problema simples. A maioria dos sistemas de visualização de impressão presumem que cada página impressa corresponde a uma página no documento.  
  
 Na tentativa de oferecer uma solução generalizada, há várias coisas a considerar. Imagine um sistema de CAD. O usuário tem um desenho que abrange várias planilhas E tamanho. Em um tamanho de E (ou menor, escala) plotadora, numeração de página seria como no caso mais simples. Mas em uma impressora a laser, imprimir páginas de um tamanho de 16 por folha, o que visualização de impressão considera uma "página"  
  
 Como o parágrafo introdutório estados, visualização de impressão está atuando como uma impressora. Portanto, o usuário verá o que seria sair da impressora específica que está selecionada. Cabe a exibição para determinar qual imagem será impressa em cada página.  
  
 A cadeia de caracteres de descrição de página no `CPrintInfo` estrutura fornece uma maneira de exibir o número da página para o usuário se ele pode ser representado como um número por página (como "Página 1" ou "páginas 1-2"). Essa cadeia de caracteres é usada pela implementação padrão de **CPreviewView::OnDisplayPageNumber**. Se for necessária uma exibição diferente, um pode anular essa função virtual para fornecer, por exemplo, "Planilha1, seções de A, B".  
  
## <a name="see-also"></a>Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)

