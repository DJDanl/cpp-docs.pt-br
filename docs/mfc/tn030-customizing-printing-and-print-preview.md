---
title: 'TN030: Personalizando impressão e visualização de impressão'
ms.date: 06/28/2018
f1_keywords:
- vc.print
helpviewer_keywords:
- TN030
- customizing printing and print preview
- printing [MFC], views
- printing views [MFC]
- print preview [MFC], customizing
ms.assetid: 32744697-c91c-41b6-9a12-b8ec01e0d438
ms.openlocfilehash: 09938c5cec2812998d5e76e15154754ad3ac3e0b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62305678"
---
# <a name="tn030-customizing-printing-and-print-preview"></a>TN030: Personalizando impressão e visualização de impressão

> [!NOTE]
> A nota técnica a seguir não foi atualizada desde que foi incluído pela primeira vez na documentação online. Como resultado, alguns procedimentos e tópicos podem estar desatualizadas ou incorretas. Para obter as informações mais recentes, é recomendável que você pesquise o tópico de interesse no índice da documentação online.

Essa observação descreve o processo de personalização de impressão e visualização de impressão e descreve a finalidade das rotinas de retorno de chamada usadas na `CView` e as rotinas de retorno de chamada e funções de membro de `CPreviewView`.

## <a name="the-problem"></a>O problema

MFC fornece uma solução completa para a maioria dos impressão e visualização de impressão precisa. Na maioria dos casos, pouco código adicional é necessário ter uma visão capaz de imprimir e visualizar. No entanto, há maneiras de otimizar a impressão que exigem um esforço significativo por parte do desenvolvedor, e alguns aplicativos precisam adicionar elementos da interface do usuário específico para o modo de visualização de impressão.

## <a name="efficient-printing"></a>Impressão eficiente

Quando um aplicativo MFC imprime usando os métodos padrão, o Windows direciona todas as chamadas de saída de Interface gráfica de dispositivo (GDI) para um metarquivo na memória. Quando `EndPage` é chamado, o Windows desempenha o metarquivo uma vez para cada faixa físico que exige que a impressora para imprimir uma página. Durante essa renderização GDI frequentemente consulta o procedimento de anular para determinar se ele deve continuar. Normalmente, o procedimento de anular permite mensagens a serem processadas para que o usuário pode anular o trabalho de impressão usando uma caixa de diálogo de impressão.

Infelizmente, isso pode reduzir o processo de impressão. Se a impressão em seu aplicativo deve ser mais rápida do que pode ser obtida usando a técnica padrão, você deve implementar bandas manual.

## <a name="print-banding"></a>Faixas de impressão

Para a banda manualmente, você deve re implementar o loop de impressão, de modo que `OnPrint` é chamado várias vezes por página (uma vez por banda). O loop de impressão é implementado de `OnFilePrint` função em viewprnt.cpp. No seu `CView`-classe, derivada sobrecarga dessa função, para que a entrada de mapa de mensagem para lidar com o comando print chama sua função de impressa. Copie o `OnFilePrint` rotina e alterar o loop de impressão para implementar a faixa. Você provavelmente também deseja passar o retângulo de faixa para suas funções de impressão para que você possa otimizar o desenho com base na seção da página que está sendo impressa.

Em segundo lugar, você deve chamar com frequência `QueryAbort` ao desenhar a faixa. Caso contrário, o procedimento de anular não será chamado e o usuário será não é possível cancelar o trabalho de impressão.

## <a name="print-preview-electronic-paper-with-user-interface"></a>Visualização de impressão: Papel eletrônico com Interface do usuário

Visualizar impressão, em essência, tenta ativar a exibição em uma emulação de uma impressora. Por padrão, a área de cliente da janela principal é usada para exibir uma ou duas páginas totalmente dentro da janela. O usuário é capaz de aplicar zoom em uma área da página para vê-lo em mais detalhes. Com suporte adicional, o usuário ainda poderá ter permissão para editar o documento no modo de visualização.

## <a name="customizing-print-preview"></a>Personalizando a visualização de impressão

Essa observação lida apenas com um aspecto da modificação de visualização de impressão: Adicionando a interface do usuário para o modo de visualização. Outras modificações são possíveis, mas essas alterações estão fora do escopo desta discussão.

## <a name="to-add-ui-to-the-preview-mode"></a>Para adicionar a interface do usuário para o modo de visualização

1. Derive uma classe de exibição de `CPreviewView`.

2. Adicione manipuladores de comandos para os aspectos da interface do usuário desejado.

3. Se você estiver adicionando os aspectos visuais na tela, substitua `OnDraw` e execute seu desenho depois de chamar `CPreviewView::OnDraw`.

## <a name="onfileprintpreview"></a>OnFilePrintPreview

Isso é o manipulador de comandos para visualização de impressão. Sua implementação do padrão é:

```cpp
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
        delete pState;  // preview failed to initialize, delete State now
    }
}
```

`DoPrintPreview` ocultará o painel principal do aplicativo. Barras de controle, como a barra de status, podem ser retidas especificando-os no pState ->*dwStates* membro (essa é uma máscara de bits e os bits para barras de controle individuais são definidas por AFX_CONTROLBAR_MASK (AFX_IDW_MYBAR)). A janela pState ->*nIDMainPane* é a janela que será automaticamente ocultada e reshown. `DoPrintPreview` em seguida, criará uma barra de botões para a interface do usuário de visualização padrão. Se for necessário tratamento especial de janela, por exemplo, para ocultar ou mostrar outras janelas, o que devem ser feitas antes da `DoPrintPreview` é chamado.

Por padrão, quando termina de visualização de impressão, ele retorna as barras de controle para seus estados originais e o painel principal para visível. Se for necessário um tratamento especial, ele deve ser feito em uma substituição de `EndPrintPreview`. Se `DoPrintPreview` falhar, também fornecem um tratamento especial.

DoPrintPreview é chamado com:

- A ID de recurso do modelo de caixa de diálogo para a barra de ferramentas de visualização.

- Um ponteiro para o modo de exibição para executar a impressão para a visualização de impressão.

- A classe de tempo de execução a visualização de classe de exibição. Isso será criado dinamicamente em DoPrintPreview.

- O ponteiro CPrintPreviewState. Observe que a estrutura CPrintPreviewState (ou a estrutura derivada se o aplicativo precisar de mais de estado preservado) deve *não* ser criado no quadro. DoPrintPreview é sem janela restrita e essa estrutura deve sobreviver até EndPrintPreview é chamado.

  > [!NOTE]
  > Se uma classe de exibição ou modo de exibição separado é necessário para suporte de impressão, um ponteiro para o objeto deve ser passado como o segundo parâmetro.

## <a name="endprintpreview"></a>EndPrintPreview

Isso é chamado para encerrar o modo de visualização de impressão. Muitas vezes é desejável para passar para a página do documento que foi exibido pela última vez na visualização de impressão. `EndPrintPreview` é a chance do aplicativo para fazer isso. -> o pInfo*m_nCurPage* membro é a página que foi exibida pela última vez (mais à esquerda se duas páginas foram exibidas) e o ponteiro é uma dica sobre onde na página do usuário estava interessado. Uma vez que a estrutura do modo de exibição do aplicativo é desconhecida para a estrutura, em seguida, você deve fornecer o código para mover para o ponto escolhido.

Você deve executar a maioria das ações antes de chamar `CView::EndPrintPreview`. Essa chamada reverte os efeitos da `DoPrintPreview` e exclui pView, pDC e pInfo.

```cpp
// Any further cleanup should be done here.
CView::EndPrintPreview(pDC, pInfo, point, pView);
```

## <a name="cwinapponfileprintsetup"></a>CWinApp::OnFilePrintSetup

Isso deve ser mapeado para o item de menu Configurar impressão. Na maioria dos casos, não é necessário substituir a implementação.

## <a name="page-nomenclature"></a>Nomenclatura de página

Outro problema é a de numeração de página e a ordem. Para aplicativos de tipo de processador de texto simples, esse é um problema simples. A maioria dos sistemas de visualização de impressão supõem que cada página impressa corresponde a uma página no documento.

Na tentativa de fornecer uma solução generalizada, há várias coisas a considerar. Imagine um sistema de CAD. O usuário tem um desenho que abrange várias planilhas E tamanho. Em um tamanho de E (ou em uma escala menor,) plotadora, numeração de página seria como no caso mais simples. Mas, em uma impressora a laser, imprimir páginas de um tamanho de 16 por folha, o que visualização de impressão, considere uma "página"

Como afirma o parágrafo introdutório, visualização de impressão está atuando como uma impressora. Portanto, o usuário verá o que virá da impressora específica que está selecionada. Cabe a exibição para determinar qual imagem é impressa em cada página.

A cadeia de caracteres de descrição de página no `CPrintInfo` estrutura fornece um meio de exibir o número da página para o usuário se ele pode ser representado como um número por página (como na "Página 1" ou "páginas 1-2"). Essa cadeia de caracteres é usada pela implementação do padrão de `CPreviewView::OnDisplayPageNumber`. Se for necessária uma exibição diferente, um pode substituir essa função virtual para fornecer, por exemplo, "Planilha1, seções de A, B".

## <a name="see-also"></a>Consulte também

[Observações técnicas por número](../mfc/technical-notes-by-number.md)<br/>
[Observações técnicas por categoria](../mfc/technical-notes-by-category.md)
