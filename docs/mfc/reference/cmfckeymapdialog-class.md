---
title: Classe CMFCKeyMapDialog | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCKeyMapDialog
- AFXKEYMAPDIALOG/CMFCKeyMapDialog
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::CMFCKeyMapDialog
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::DoModal
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::FormatItem
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::GetCommandKeys
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::OnInsertItem
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::OnPrintHeader
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::OnPrintItem
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::OnSetColumns
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::PrintKeyMap
- AFXKEYMAPDIALOG/CMFCKeyMapDialog::SetColumnsWidth
dev_langs:
- C++
helpviewer_keywords:
- CMFCKeyMapDialog [MFC], CMFCKeyMapDialog
- CMFCKeyMapDialog [MFC], DoModal
- CMFCKeyMapDialog [MFC], FormatItem
- CMFCKeyMapDialog [MFC], GetCommandKeys
- CMFCKeyMapDialog [MFC], OnInsertItem
- CMFCKeyMapDialog [MFC], OnPrintHeader
- CMFCKeyMapDialog [MFC], OnPrintItem
- CMFCKeyMapDialog [MFC], OnSetColumns
- CMFCKeyMapDialog [MFC], PrintKeyMap
- CMFCKeyMapDialog [MFC], SetColumnsWidth
ms.assetid: 5feb4942-d636-462d-a162-0104dd320f4e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1965e5dd2d522175b3709449df9a0b8575e20c59
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfckeymapdialog-class"></a>Classe CMFCKeyMapDialog
O `CMFCKeyMapDialog` classe oferece suporte a um controle que mapeia os comandos para chaves no teclado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCKeyMapDialog : public CDialogEx  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCKeyMapDialog::CMFCKeyMapDialog](#cmfckeymapdialog)|Constrói um objeto `CMFCKeyMapDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCKeyMapDialog::DoModal](#domodal)|Exibe uma caixa de diálogo de mapeamento do teclado.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCKeyMapDialog::FormatItem](#formatitem)|Chamado pelo framework para criar uma cadeia de caracteres que descreve um mapeamento de chaves. Por padrão, a cadeia de caracteres contém o nome do comando, as teclas de atalho usadas e a descrição de teclas de atalho.|  
|[CMFCKeyMapDialog::GetCommandKeys](#getcommandkeys)|Recupera uma cadeia de caracteres que contém uma lista de teclas de atalho associada com o comando especificado.|  
|[CMFCKeyMapDialog::OnInsertItem](#oninsertitem)|Chamado pelo framework antes de um novo item é inserido no controle de lista interna que suporta o controle de mapeamento de teclado.|  
|[CMFCKeyMapDialog::OnPrintHeader](#onprintheader)|Chamado pelo framework para imprimir o cabeçalho para o mapa do teclado em uma nova página.|  
|[CMFCKeyMapDialog::OnPrintItem](#onprintitem)|Chamado pelo framework para imprimir um item de mapeamento de teclado.|  
|[CMFCKeyMapDialog::OnSetColumns](#onsetcolumns)|Chamado pelo framework para definir as legendas para as colunas no controle de lista interna que suporta o controle de mapeamento de teclado.|  
|[CMFCKeyMapDialog::PrintKeyMap](#printkeymap)|Chamado pelo framework quando um usuário clica o **impressão** botão.|  
|[CMFCKeyMapDialog::SetColumnsWidth](#setcolumnswidth)|Chamado pelo framework para definir a largura das colunas no controle de lista interna que suporta o controle de mapeamento de teclado.|  
  
## <a name="remarks"></a>Comentários  
 Use o `CMFCKeyMapDialog` classe para implementar uma caixa de diálogo de mapeamento de teclado redimensionável. A caixa de diálogo usa um controle de exibição de lista para exibir os atalhos de teclado e os comandos associados.  
  
 Para usar o `CMFCKeyMapDialog` classe em um aplicativo, transmitir um ponteiro para a janela do quadro principal como um parâmetro para o `CMFCKeyMapDialog` construtor. Em seguida, chamar o `DoModal` método para iniciar a caixa de diálogo modal.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CDialog](../../mfc/reference/cdialog-class.md)  
  
 [CDialogEx](../../mfc/reference/cdialogex-class.md)  
  
 [CMFCKeyMapDialog](../../mfc/reference/cmfckeymapdialog-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxkeymapdialog.h  
  
##  <a name="cmfckeymapdialog"></a>CMFCKeyMapDialog::CMFCKeyMapDialog  
 Constrói um objeto `CMFCKeyMapDialog`.  
  
```  
CMFCKeyMapDialog(
    CFrameWnd* pWndParentFrame,  
    BOOL bEnablePrint=FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pWndParentFrame`  
 Um ponteiro para a janela pai do `CMFCKeyMapDialog` objeto.  
  
 [in] `bEnablePrint`  
 `TRUE`Se a lista de teclas de aceleração que pode ser impressos; Caso contrário, `FALSE`. O padrão é `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um objeto de `CMFCKeyMapDialog` classe. Este exemplo é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo#21](../../mfc/codesnippet/cpp/cmfckeymapdialog-class_1.cpp)]  
  
##  <a name="domodal"></a>CMFCKeyMapDialog::DoModal  
 Exibe uma caixa de diálogo de mapeamento do teclado.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro com sinal, como `IDOK` ou `IDCANCEL`, que é passado para o [CDialog::EndDialog](../../mfc/reference/cdialog-class.md#enddialog) método. O método, por sua vez, fecha a caixa de diálogo. Para obter mais informações, consulte [CDialog::DoModal](../../mfc/reference/cdialog-class.md#domodal).  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo de mapeamento de teclado permite selecionar e atribuir as teclas de aceleração para várias categorias de comandos. Além disso, você pode copiar as teclas de aceleração selecionado e sua descrição na área de transferência.  
  
##  <a name="formatitem"></a>CMFCKeyMapDialog::FormatItem  
 Chamado pelo framework para criar uma cadeia de caracteres que descreve um mapeamento de chaves. Por padrão, a cadeia de caracteres contém o nome do comando, as teclas de atalho usadas e a descrição de teclas de atalho.  
  
```  
virtual CString FormatItem(int nItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nItem`  
 O índice de base zero de um item na lista interna de mapeamentos de chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto do item formatado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcommandkeys"></a>CMFCKeyMapDialog::GetCommandKeys  
 Recupera um valor de cadeia de caracteres. A cadeia de caracteres contém uma lista de teclas de atalho que estão associados um comando especificado.  
  
```  
virtual CString GetCommandKeys(UINT uiCmdID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Uma ID de comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um delimitada por ponto e vírgula (';') lista de teclas de atalho que está associada com o comando especificado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="oninsertitem"></a>CMFCKeyMapDialog::OnInsertItem  
 Chamado pelo framework antes de um novo item é inserido em um controle de lista interna que suporta o controle de mapeamento de teclado.  
  
```  
virtual void OnInsertItem(
    CMFCToolBarButton* pButton,  
    int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Um ponteiro para um botão de barra de ferramentas que é usado para mapear uma combinação de teclas do teclado para um nome de comando e uma descrição. O item de mapa de chave é armazenado em um controle de lista interna.  
  
 [in] `nItem`  
 Um índice de base zero que especifica o local inserir o novo item de mapa de chave na lista interna de controle.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onprintheader"></a>CMFCKeyMapDialog::OnPrintHeader  
 Chamado pelo framework para imprimir o cabeçalho para o mapa do teclado em uma nova página.  
  
```  
virtual int OnPrintHeader(
    CDC& dc,  
    int nPage,  
    int cx) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dc`  
 O contexto de dispositivo para a impressora.  
  
 [in] `nPage`  
 O número de página para imprimir.  
  
 [in] `cx`  
 O deslocamento horizontal do cabeçalho, em pixels.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, a altura do texto. Para obter mais informações, consulte a seção do valor de retorno de [CDC::DrawText](../../mfc/reference/cdc-class.md#drawtext).  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa esse método para imprimir o mapa do teclado. Por padrão, esse método imprime o número da página, o nome do aplicativo e o título da caixa de diálogo.  
  
##  <a name="onprintitem"></a>CMFCKeyMapDialog::OnPrintItem  
 Chamado pelo framework para imprimir um item de mapeamento de teclado.  
  
```  
virtual int OnPrintItem(
    CDC& dc,  
    int nItem,  
    int y,  
    int cx,  
    BOOL bCalcHeight) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `dc`  
 O contexto de dispositivo da impressora.  
  
 [in] `nItem`  
 O índice de base zero do item para imprimir.  
  
 [in] `y`  
 O deslocamento vertical entre a parte superior da página e a posição do item.  
  
 [in] `cx`  
 O deslocamento horizontal à esquerda da página e a posição do item.  
  
 [in] `bCalcHeight`  
 `TRUE`para calcular a altura recomendada para o item de impressão; `FALSE` para truncar o item de impressão para que ele se ajuste de espaço padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura do item impresso.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para imprimir um item de caixa de diálogo de mapa de chave. Por padrão, esse método imprime o nome do comando, as teclas de atalho e descrição de comando do item.  
  
##  <a name="onsetcolumns"></a>CMFCKeyMapDialog::OnSetColumns  
 Chamado pelo framework para definir as legendas para as colunas no controle de lista interna que suporta o controle de mapeamento de teclado.  
  
```  
virtual void OnSetColumns();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método obtém as legendas para as colunas de três recursos. A legenda da coluna de comando é de IDS_AFXBARRES_COMMAND, a legenda da coluna de chave é de IDS_AFXBARRES_KEYS e a legenda da coluna de descrição é de IDS_AFXBARRES_DESCRIPTION.  
  
##  <a name="printkeymap"></a>CMFCKeyMapDialog::PrintKeyMap  
 Chamado pelo framework quando um usuário clica o **impressão** botão.  
  
```  
virtual void PrintKeyMap();
```  
  
### <a name="remarks"></a>Comentários  
 O `PrintKeyMap` método imprime o mapa da chave. Ele inicia um novo trabalho de impressão e, em seguida, chama repetidamente o [CMFCKeyMapDialog::OnPrintHeader](#onprintheader) e [CMFCKeyMapDialog::OnPrintItem](#onprintitem) métodos até que todos os mapeamentos de chave são impressas.  
  
##  <a name="setcolumnswidth"></a>CMFCKeyMapDialog::SetColumnsWidth  
 Chamado pelo framework para definir a largura das colunas no controle de lista interna que suporta o controle de mapeamento de teclado.  
  
```  
virtual void SetColumnsWidth();
```  
  
### <a name="remarks"></a>Comentários  
 Este método define a lista interna colunas do controle larguras padrão. Primeiro, a largura da coluna de teclas de atalho é calculada. Em seguida, um terço a largura restante é alocado para a coluna de comando e os outros dois terços alocada para a coluna de descrição.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)
