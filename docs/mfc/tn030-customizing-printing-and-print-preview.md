---
title: "TN030: personalizando impress&#227;o e visualiza&#231;&#227;o de impress&#227;o | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.print"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "personalizando impressão e visualização de impressão"
  - "visualizar impressão, personalizando"
  - "imprimindo [MFC], modos de exibição"
  - "imprimindo exibições"
  - "TN030"
ms.assetid: 32744697-c91c-41b6-9a12-b8ec01e0d438
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN030: personalizando impress&#227;o e visualiza&#231;&#227;o de impress&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 Essa observação descreve o processo de personalizar a impressão e a visualização de impressão e descreve as finalidades de rotinas de retorno de chamada usadas em `CView` e as rotinas de retorno de chamada e as funções de membro de **CPreviewView**.  
  
## O problema  
 MFC O fornece uma solução completo para a maioria das necessidades de impressão e visualizar impressão.  Na maioria dos casos, vez código adicional é necessária para ter uma exibição capaz de imprimir e visualizar.  No entanto, há maneiras de otimizar a impressão de que exigem a tensão significativa da parte do desenvolvedor, e alguns aplicativos precisam adicionar elementos específicos da interface do usuário no modo de visualização da impressão.  
  
## Impressão eficiente  
 Quando um aplicativo MFC será impressa usando os métodos padrão, o windows direcionam todas as chamadas gráficos de saída de \(GDI\) da interface de dispositivo metarquivo de memória.  Quando `EndPage` é chamado, o windows executam o metarquivo uma vez para cada físico a faixa da impressora requer para imprimir uma página.  Durante a renderização, GDI consulta que frequência o procedimento de anulação para determinar se continuar.  Normalmente o procedimento de anulação permite que as mensagens sejam processadas de forma que o usuário pode anular o trabalho de cópia usando uma caixa de diálogo de impressão.  
  
 Infelizmente, isso pode reduzir o processo de impressão.  Se a impressão em seu aplicativo deve ser mais rápido do que pode ser obtida usando a técnica padrão, você deve implementar a borda manual.  
  
## A borda de cópia  
 Para unir\-se manualmente, você deve com referência ao implementar o loop de cópia de modo que `OnPrint` for chamado várias vezes por página \(uma vez por linha distribuída\).  O loop de impressão é implementado na função de **OnFilePrint** em viewprnt.cpp.  No `CView`\- classe derivada, você sobrecarregar essa função para que a entrada da mensagem para tratar o comando copiar chama a função de cópia.  Copie a rotina de **OnFilePrint** e alterar o loop de cópia para implementar a borda.  Você provavelmente também pode querer passe o retângulo de borda às funções de impressão de forma que você possa otimizar o desenho com base na seção da página que está sendo impressa.  
  
 Segundo, você normalmente deve chamar `QueryAbort` ao chamar a faixa.  Caso contrário, o procedimento de anulação não será chamado e o usuário não poderá cancelar do trabalho de cópia.  
  
## Visualização de impressão: O papel eletrônico com a interface do usuário  
 Visualização de impressão, basicamente, o tenta transformar a exibição em uma emulação de uma impressora.  Por padrão, a área do cliente da janela principal é usada para exibir totalmente uma ou duas páginas dentro da janela.  O usuário pode ampliar em uma área da página para consulta com mais detalhes.  Com suporte adicional, o mesmo usuário pode ser permitido editar o documento em modo de visualização.  
  
## Personalizando a visualização de impressão  
 Essa observe o trata apenas um aspecto de visualização da impressão de alteração: Adicionando interface do usuário para o modo de visualização.  Outras alterações são possíveis, mas tais alterações estão fora do escopo desta discussão.  
  
## Para adicionar interface do usuário para o modo de visualização  
  
1.  Derivar uma classe de exibição de **CPreviewView**.  
  
2.  Adicionar manipuladores de comando para os aspectos de interface do usuário que você deseja.  
  
3.  Se você estiver adicionando aspectos visuais à exibição, a substituição `OnDraw` e executando o desenho depois de chamar **CPreviewView::OnDraw.**  
  
## OnFilePrintPreview  
 Este é o manipulador de comando para a visualização de impressão.  Sua implementação padrão é:  
  
```  
void CView::OnFilePrintPreview()  
{  
    // In derived classes, implement special window handling here  
    // Be sure to Unhook Frame Window close if hooked.  
  
    // must not create this on the frame. Must outlive this function  
    CPrintPreviewState* pState = new CPrintPreviewState;  
  
    if (!DoPrintPreview(AFX_IDD_PREVIEW_TOOLBAR, this,  
                RUNTIME_CLASS(CPreviewView), pState))  
    {  
        // In derived classes, reverse special window handling  
        // here for Preview failure case  
  
        TRACE0("Error: DoPrintPreview failed");  
        AfxMessageBox(AFX_IDP_COMMAND_FAILURE);  
        delete pState;      // preview failed to initialize,   
                    // delete State now  
    }  
}  
```  
  
 **DoPrintPreview** ocultará o painel principal do aplicativo.  As barras de controle, como a barra de status, podem ser retidas especificando\-os no membro\>de**dwStates** de pState\- \(é um bitmask e os bits de barras de controle individuais são definidos por **AFX\_CONTROLBAR\_MASK**AFX\_IDW\_MYBAR \(\)\).  O pState\-**nIDMainPane** \>da janela é a janela que será oculta automaticamente e reshown.  **DoPrintPreview** criará uma barra de botões para a visualização padrão interface do usuário.  Se a manipulação especial da janela é necessária, como ocultar ou mostrar outras janelas, que devem ser feitas antes que **DoPrintPreview** ser chamado.  
  
 Por padrão, quando a visualização de impressão é concluída, retornará as barras de controle para seus estados original e ao painel principal a visível.  Se a manipulação especial é necessária, deve ser feita em uma substituição de **EndPrintPreview.** Se **DoPrintPreview** falha, fornecer a manipulação especial.  
  
 DoPrintPreview é chamado com:  
  
-   A ID do recurso do modelo da caixa de diálogo para a barra de ferramentas de visualização.  
  
-   Um ponteiro para a exibição para executar a impressão para a visualização de impressão.  
  
-   A classe de tempo de execução da classe da exibição visualização.  Isso será criado dinamicamente em DoPrintPreview.  
  
-   O ponteiro de CPrintPreviewState.  Observe que a estrutura de CPrintPreviewState \(ou a estrutura derivado se o aplicativo precisar de mais estado preservado\) *não*  devem ser criadas no quadro.  DoPrintPreview é modeless e essa estrutura deve EndPrintPreview sobreviver até que seja chamado.  
  
    > [!NOTE]
    >  Se uma exibição ou uma classe separada de exibição são necessárias para imprimir o suporte, um ponteiro para o objeto deve ser passado como o segundo parâmetro.  
  
## EndPrintPreview  
 Isso é chamado para finalizar o modo de visualização da impressão.  Geralmente é desejável mover para a página no documento que foi exibido na visualização de impressão.  **EndPrintPreview** é a possibilidade de aplicativo para fazer isso.  O membro\>de`m_nCurPage` de pInfo\- é a página que foi exibido \(a mais à esquerda se duas páginas são exibidas\), e o ponteiro é uma dica a respeito de onde na página o usuário está interessado.  Desde que a estrutura de exibição de aplicativo é desconhecida à estrutura, você deve fornecer o código ao mover para o ponto selecionado.  
  
 Você deve executar a maioria das ações antes de chamar **CView::EndPrintPreview**.  Essa chamada inverte os efeitos de **DoPrintPreview** e exclui o pView, o pDC, e o pInfo.  
  
```  
// Any further cleanup should be done here.  
CView::EndPrintPreview(pDC, pInfo, point, pView);  
```  
  
## CWinApp::OnFilePrintSetup  
 Isso deve ser mapeado para o item de menu de configuração de cópia.  Na maioria dos casos, não é necessário substituir a implementação.  
  
## Nomenclatura de página  
 Outros tema que são de numeração e da ordem de página.  Para aplicativos simples do tipo de processador de textos, esse é um problema simples.  A maioria dos sistemas de visualização de impressão assumem que cada página impressa corresponde a uma página no documento.  
  
 Tente fornecer uma solução generalizada, há várias coisas a serem considerados.  Imagine um sistema de CAD.  O usuário tem um desenho que abrange várias folhas de E\- tamanho.  Em um plotador de E\- tamanho \(ou um secundário, dimensionado\), a numeração de página seria como no caso simples.  Mas em uma impressora a laser, imprimindo 16 páginas de um tamanho por folha, que a visualização de impressão considera uma página”? “  
  
 Como os estados introdutórios de parágrafo, a visualização de impressão está atuando como uma impressora.  Em virtude disso, o usuário verá o que deixa da impressora específico que está selecionada.  É responsabilidade a exibição para determinar quais imagem é impressa em cada página.  
  
 A cadeia de caracteres de descrição da página na estrutura de `CPrintInfo` fornece uma maneira de exibir o número da página ao usuário se pode ser representada como um número por página \(como na página “1 " ou “nas páginas 1\-2”\). Essa cadeia de caracteres é usada pela implementação padrão de **CPreviewView::OnDisplayPageNumber**.  Se uma exibição diferente for necessária, se pode substituir essa função virtual para fornecer, por exemplo, “Sheet1 seções, A, B”.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)