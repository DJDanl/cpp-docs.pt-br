---
title: Classe CMFCKeyMapDialog | Documentos do Microsoft
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
- CMFCKeyMapDialog class
ms.assetid: 5feb4942-d636-462d-a162-0104dd320f4e
caps.latest.revision: 26
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 6599f5c3cda6eb407f4545d42528c1c68950b94c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cmfckeymapdialog-class"></a>Classe CMFCKeyMapDialog
O `CMFCKeyMapDialog` classe oferece suporte a um controle que mapeia comandos para teclas no teclado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCKeyMapDialog : public CDialogEx  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
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
|[CMFCKeyMapDialog::FormatItem](#formatitem)|Chamado pela estrutura para criar uma cadeia de caracteres que descreve um mapeamento de chave. Por padrão, a cadeia de caracteres contém o nome do comando, as teclas de atalho usadas e a descrição de teclas de atalho.|  
|[CMFCKeyMapDialog::GetCommandKeys](#getcommandkeys)|Recupera uma cadeia de caracteres que contém uma lista das teclas de atalho associadas com o comando especificado.|  
|[CMFCKeyMapDialog::OnInsertItem](#oninsertitem)|Chamado pela estrutura antes que um novo item é inserido no controle de lista interna que suporta o controle de mapeamento de teclado.|  
|[CMFCKeyMapDialog::OnPrintHeader](#onprintheader)|Chamado pela estrutura para imprimir o cabeçalho para o mapa do teclado em uma nova página.|  
|[CMFCKeyMapDialog::OnPrintItem](#onprintitem)|Chamado pela estrutura para imprimir um item de mapeamento de teclado.|  
|[CMFCKeyMapDialog::OnSetColumns](#onsetcolumns)|Chamado pela estrutura para definir as legendas para as colunas na lista interna de controle que suporta o controle de mapeamento de teclado.|  
|[CMFCKeyMapDialog::PrintKeyMap](#printkeymap)|Chamado pela estrutura quando um usuário clica o **impressão** botão.|  
|[CMFCKeyMapDialog::SetColumnsWidth](#setcolumnswidth)|Chamado pela estrutura para definir a largura das colunas na lista interna de controle que suporta o controle de mapeamento de teclado.|  
  
## <a name="remarks"></a>Comentários  
 Use o `CMFCKeyMapDialog` classe para implementar uma caixa de diálogo de mapeamento de teclado redimensionável. A caixa de diálogo usa um controle de exibição de lista para exibir os atalhos de teclado e os comandos associados.  
  
 Para usar o `CMFCKeyMapDialog` da classe em um aplicativo, passe um ponteiro para a janela do quadro principal como um parâmetro para o `CMFCKeyMapDialog` construtor. Em seguida, chamar o `DoModal` método para iniciar a caixa de diálogo modal.  
  
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
 `TRUE`Se a lista de teclas de aceleração pode ser impressa; Caso contrário, `FALSE`. O padrão é `FALSE`.  
  
### <a name="remarks"></a>Comentários  
  
### <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como criar um objeto de `CMFCKeyMapDialog` classe. Este exemplo é parte do [exemplo de demonstração do Visual Studio](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_VisualStudioDemo&#21;](../../mfc/codesnippet/cpp/cmfckeymapdialog-class_1.cpp)]  
  
##  <a name="domodal"></a>CMFCKeyMapDialog::DoModal  
 Exibe uma caixa de diálogo de mapeamento do teclado.  
  
```  
virtual INT_PTR DoModal();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um inteiro, como `IDOK` ou `IDCANCEL`, que é passado para o [CDialog::EndDialog](../../mfc/reference/cdialog-class.md#enddialog) método. O método, por sua vez, fecha a caixa de diálogo. Para obter mais informações, consulte [CDialog::DoModal](../../mfc/reference/cdialog-class.md#domodal).  
  
### <a name="remarks"></a>Comentários  
 A caixa de diálogo de mapeamento de teclado permite selecionar e atribuir teclas de aceleração para várias categorias de comandos. Além disso, você pode copiar as teclas de aceleração selecionado e sua descrição para a área de transferência.  
  
##  <a name="formatitem"></a>CMFCKeyMapDialog::FormatItem  
 Chamado pela estrutura para criar uma cadeia de caracteres que descreve um mapeamento de chave. Por padrão, a cadeia de caracteres contém o nome do comando, as teclas de atalho usadas e a descrição de teclas de atalho.  
  
```  
virtual CString FormatItem(int nItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `nItem`  
 O índice com base em zero de um item na lista interna de mapeamentos de chave.  
  
### <a name="return-value"></a>Valor de retorno  
 Um `CString` objeto que contém o texto do item formatado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="getcommandkeys"></a>CMFCKeyMapDialog::GetCommandKeys  
 Recupera um valor de cadeia de caracteres. A cadeia de caracteres contém uma lista de teclas de atalho associadas um comando especificado.  
  
```  
virtual CString GetCommandKeys(UINT uiCmdID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `uiCmdID`  
 Uma ID de comando.  
  
### <a name="return-value"></a>Valor de retorno  
 Um-separados por vírgula (';') lista de teclas de atalho que está associada com o comando especificado.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="oninsertitem"></a>CMFCKeyMapDialog::OnInsertItem  
 Chamado pela estrutura antes que um novo item é inserido em um controle de lista interna que suporta o controle de mapeamento de teclado.  
  
```  
virtual void OnInsertItem(
    CMFCToolBarButton* pButton,  
    int nItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pButton`  
 Um ponteiro para um botão de barra de ferramentas que é usado para mapear uma combinação de teclas do teclado para um nome de comando e uma descrição. O item de mapa de chaves é armazenado em um controle de lista interna.  
  
 [in] `nItem`  
 Um índice baseado em zero que especifica o local inserir o novo item de mapa de chave no controle de lista interna.  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="onprintheader"></a>CMFCKeyMapDialog::OnPrintHeader  
 Chamado pela estrutura para imprimir o cabeçalho para o mapa do teclado em uma nova página.  
  
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
 Se for bem-sucedido, a altura do texto. Para obter mais informações, consulte a seção de valor de retorno de [CDC::DrawText](../../mfc/reference/cdc-class.md#drawtext).  
  
### <a name="remarks"></a>Comentários  
 A estrutura usa esse método para imprimir o mapa do teclado. Por padrão, esse método imprime o número da página, o nome do aplicativo e o título da caixa de diálogo.  
  
##  <a name="onprintitem"></a>CMFCKeyMapDialog::OnPrintItem  
 Chamado pela estrutura para imprimir um item de mapeamento de teclado.  
  
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
 O índice baseado em zero do item para imprimir.  
  
 [in] `y`  
 O deslocamento vertical entre a parte superior da página e a posição do item.  
  
 [in] `cx`  
 O deslocamento horizontal à esquerda da página e a posição do item.  
  
 [in] `bCalcHeight`  
 `TRUE`para calcular a altura recomendada para o item de impressão; `FALSE` para truncar o item de impressão para que ela caiba espaço padrão.  
  
### <a name="return-value"></a>Valor de retorno  
 A altura do item impressa.  
  
### <a name="remarks"></a>Comentários  
 O framework chama esse método para imprimir um item de caixa de diálogo de mapa de chave. Por padrão, esse método imprime o nome do comando do item, as teclas de atalho e descrição do comando.  
  
##  <a name="onsetcolumns"></a>CMFCKeyMapDialog::OnSetColumns  
 Chamado pela estrutura para definir as legendas para as colunas na lista interna de controle que suporta o controle de mapeamento de teclado.  
  
```  
virtual void OnSetColumns();
```  
  
### <a name="remarks"></a>Comentários  
 Por padrão, esse método obtém as legendas para colunas de três recursos. A legenda da coluna de comando é de IDS_AFXBARRES_COMMAND, a legenda da coluna de chave é de IDS_AFXBARRES_KEYS e a legenda da coluna de descrição é de IDS_AFXBARRES_DESCRIPTION.  
  
##  <a name="printkeymap"></a>CMFCKeyMapDialog::PrintKeyMap  
 Chamado pela estrutura quando um usuário clica o **impressão** botão.  
  
```  
virtual void PrintKeyMap();
```  
  
### <a name="remarks"></a>Comentários  
 O `PrintKeyMap` método imprime o mapa da chave. Ele inicia um novo trabalho de impressão e, em seguida, chama repetidamente a [CMFCKeyMapDialog::OnPrintHeader](#onprintheader) e [CMFCKeyMapDialog::OnPrintItem](#onprintitem) métodos até que todos os mapeamentos de chaves são impressas.  
  
##  <a name="setcolumnswidth"></a>CMFCKeyMapDialog::SetColumnsWidth  
 Chamado pela estrutura para definir a largura das colunas na lista interna de controle que suporta o controle de mapeamento de teclado.  
  
```  
virtual void SetColumnsWidth();
```  
  
### <a name="remarks"></a>Comentários  
 Este método define a lista interna colunas do controle larguras padrão. Primeiro, a largura da coluna de teclas de atalho é calculada. Em seguida, um terço da largura restante é alocado para a coluna de comando e os outros dois terços alocada para a coluna de descrição.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)

