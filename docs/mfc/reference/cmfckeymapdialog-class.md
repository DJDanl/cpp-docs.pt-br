---
title: CMFCKeyMapSala Class
ms.date: 11/04/2016
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
ms.openlocfilehash: 22aa006ce214ca720192bb761e2ff2b35a64fce3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374410"
---
# <a name="cmfckeymapdialog-class"></a>CMFCKeyMapSala Class

A `CMFCKeyMapDialog` classe suporta um controle que mapeia comandos para teclas no teclado.

## <a name="syntax"></a>Sintaxe

```
class CMFCKeyMapDialog : public CDialogEx
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCKeymapdiálogo::CMFCKeyMapDialog](#cmfckeymapdialog)|Constrói um objeto `CMFCKeyMapDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CMFCKeyMapDiálogo::DoModal](#domodal)|Exibe uma caixa de diálogo de mapeamento de teclado.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CMFCKeyMapDiálogo::Formatite](#formatitem)|Chamado pela estrutura para construir uma string que descreve um mapeamento de chave. Por padrão, a seqüência contém o nome do comando, as teclas de atalho usadas e a descrição da tecla de atalho.|
|[CMFCKeyMapDiálogo::obterchaves de comando](#getcommandkeys)|Recupera uma seqüência que contém uma lista de teclas de atalho associadas ao comando especificado.|
|[CMFCKeyMapDiálogo::OnInsertItem](#oninsertitem)|Chamado pela estrutura antes de um novo item ser inserido no controle de lista interna que suporta o controle de mapeamento do teclado.|
|[CMFCKeyMapDiálogo::OnprintHeader](#onprintheader)|Chamado pela estrutura para imprimir o cabeçalho para o mapa do teclado em uma nova página.|
|[CMFCKeyMapDiálogo::OnPrintItem](#onprintitem)|Chamado pela estrutura para imprimir um item de mapeamento do teclado.|
|[CMFCKeyMapDiálogo::Colunas de início](#onsetcolumns)|Chamado pela estrutura para definir legendas para as colunas no controle de lista interna que suporta o controle de mapeamento do teclado.|
|[CMFCKeyMapDiálogo::PrintKeyMap](#printkeymap)|Chamado pela estrutura quando um usuário clica no botão **Imprimir.**|
|[CMFCKeyMapDiálogo::ConjuntoColunasLargura](#setcolumnswidth)|Chamado pela estrutura para definir a largura das colunas no controle de lista interna que suporta o controle de mapeamento do teclado.|

## <a name="remarks"></a>Comentários

Use `CMFCKeyMapDialog` a classe para implementar uma caixa de diálogo de mapeamento de teclado resizável. A caixa de diálogo usa um controle de exibição de lista para exibir atalhos de teclado e seus comandos associados.

Para usar `CMFCKeyMapDialog` a classe em um aplicativo, passe um ponteiro para `CMFCKeyMapDialog` a janela do quadro principal como um parâmetro para o construtor. Em seguida, chame o `DoModal` método para iniciar uma caixa de diálogo modal.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Cdialogex](../../mfc/reference/cdialogex-class.md)

[Cmfckeymapdialog](../../mfc/reference/cmfckeymapdialog-class.md)

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxkeymapdialog.h

## <a name="cmfckeymapdialogcmfckeymapdialog"></a><a name="cmfckeymapdialog"></a>CMFCKeymapdiálogo::CMFCKeyMapDialog

Constrói um objeto `CMFCKeyMapDialog`.

```
CMFCKeyMapDialog(
    CFrameWnd* pWndParentFrame,
    BOOL bEnablePrint=FALSE);
```

### <a name="parameters"></a>Parâmetros

*pWndParentframe*<br/>
[em] Um ponteiro para a `CMFCKeyMapDialog` janela pai do objeto.

*bEnablePrint*<br/>
[em] VERDADE se a lista de chaves do acelerador puder ser impressa; caso contrário, FALSE. O padrão é FALSO.

### <a name="remarks"></a>Comentários

### <a name="example"></a>Exemplo

O exemplo a seguir demonstra como `CMFCKeyMapDialog` construir um objeto da classe. Este exemplo faz parte da [amostra visual studio demo](../../overview/visual-cpp-samples.md).

[!code-cpp[NVC_MFC_VisualStudioDemo#21](../../mfc/codesnippet/cpp/cmfckeymapdialog-class_1.cpp)]

## <a name="cmfckeymapdialogdomodal"></a><a name="domodal"></a>CMFCKeyMapDiálogo::DoModal

Exibe uma caixa de diálogo de mapeamento de teclado.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Um inteiro assinado, como IDOK ou IDCANCEL, que é passado para o método [CDialog::EndDialog.](../../mfc/reference/cdialog-class.md#enddialog) O método, por sua vez, fecha a caixa de diálogo. Para obter mais informações, consulte [CDialog::DoModal](../../mfc/reference/cdialog-class.md#domodal).

### <a name="remarks"></a>Comentários

A caixa de diálogo de mapeamento do teclado permite selecionar e atribuir teclas do acelerador a várias categorias de comandos. Além disso, você pode copiar as teclas do acelerador selecionadas e sua descrição na área de transferência.

## <a name="cmfckeymapdialogformatitem"></a><a name="formatitem"></a>CMFCKeyMapDiálogo::Formatite

Chamado pela estrutura para construir uma string que descreve um mapeamento de chave. Por padrão, a seqüência contém o nome do comando, as teclas de atalho usadas e a descrição da tecla de atalho.

```
virtual CString FormatItem(int nItem) const;
```

### <a name="parameters"></a>Parâmetros

*Nitem*<br/>
[em] O índice baseado em zero de um item na lista interna de mapeamentos-chave.

### <a name="return-value"></a>Valor retornado

Um `CString` objeto que contém o texto do item formatado.

### <a name="remarks"></a>Comentários

## <a name="cmfckeymapdialoggetcommandkeys"></a><a name="getcommandkeys"></a>CMFCKeyMapDiálogo::obterchaves de comando

Recupera um valor de seqüência. A seqüência contém uma lista de teclas de atalho associadas a um comando especificado.

```
virtual CString GetCommandKeys(UINT uiCmdID) const;
```

### <a name="parameters"></a>Parâmetros

*uiCmdID*<br/>
[em] Uma id de comando.

### <a name="return-value"></a>Valor retornado

Uma lista de teclas de atalho delimitadas em ponto e vírgula (';') de teclas de atalho associadas ao comando especificado.

### <a name="remarks"></a>Comentários

## <a name="cmfckeymapdialogoninsertitem"></a><a name="oninsertitem"></a>CMFCKeyMapDiálogo::OnInsertItem

Chamado pela estrutura antes de um novo item ser inserido em um controle de lista interna que suporta o controle de mapeamento do teclado.

```
virtual void OnInsertItem(
    CMFCToolBarButton* pButton,
    int nItem);
```

### <a name="parameters"></a>Parâmetros

*Pbutton*<br/>
[em] Um ponteiro para um botão de barra de ferramentas que é usado para mapear uma combinação de teclas de teclado para um nome de comando e descrição. O item do mapa-chave é armazenado em um controle de lista interna.

*Nitem*<br/>
[em] Um índice baseado em zero que especifica onde inserir o novo item do mapa-chave no controle de lista interna.

### <a name="remarks"></a>Comentários

## <a name="cmfckeymapdialogonprintheader"></a><a name="onprintheader"></a>CMFCKeyMapDiálogo::OnprintHeader

Chamado pela estrutura para imprimir o cabeçalho para o mapa do teclado em uma nova página.

```
virtual int OnPrintHeader(
    CDC& dc,
    int nPage,
    int cx) const;
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
[em] O contexto do dispositivo para a impressora.

*Npage*<br/>
[em] O número da página para imprimir.

*Cx*<br/>
[em] O deslocamento horizontal do cabeçalho, em pixels.

### <a name="return-value"></a>Valor retornado

Se for bem sucedido, a altura do texto impresso. Para obter mais informações, consulte a seção Valor de retorno do [CDC::DrawText](../../mfc/reference/cdc-class.md#drawtext).

### <a name="remarks"></a>Comentários

A estrutura usa este método para imprimir o mapa do teclado. Por padrão, este método imprime o número da página, o nome do aplicativo e o título da caixa de diálogo.

## <a name="cmfckeymapdialogonprintitem"></a><a name="onprintitem"></a>CMFCKeyMapDiálogo::OnPrintItem

Chamado pela estrutura para imprimir um item de mapeamento do teclado.

```
virtual int OnPrintItem(
    CDC& dc,
    int nItem,
    int y,
    int cx,
    BOOL bCalcHeight) const;
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
[em] O contexto do dispositivo da impressora.

*Nitem*<br/>
[em] O índice baseado em zero do item a ser impresso.

*Y*<br/>
[em] O deslocamento vertical entre a parte superior da página e a posição do item.

*Cx*<br/>
[em] O deslocamento horizontal entre a esquerda da página e a posição do item.

*bCalcHeight*<br/>
[em] TRUE para calcular a melhor altura para o item de impressão; FALSO para truncar o item de impressão de modo que ele se encaixe no espaço padrão.

### <a name="return-value"></a>Valor retornado

A altura do item impresso.

### <a name="remarks"></a>Comentários

A estrutura chama esse método para imprimir um item da caixa de diálogo do mapa chave. Por padrão, este método imprime o nome de comando do item, as teclas de atalho e a descrição do comando.

## <a name="cmfckeymapdialogonsetcolumns"></a><a name="onsetcolumns"></a>CMFCKeyMapDiálogo::Colunas de início

Chamado pela estrutura para definir legendas para as colunas no controle de lista interna que suporta o controle de mapeamento do teclado.

```
virtual void OnSetColumns();
```

### <a name="remarks"></a>Comentários

Por padrão, este método obtém as legendas para as colunas a partir de três recursos. A legenda da coluna de comando é de IDS_AFXBARRES_COMMAND, a legenda da coluna-chave é de IDS_AFXBARRES_KEYS, e a legenda da coluna de descrição é de IDS_AFXBARRES_DESCRIPTION.

## <a name="cmfckeymapdialogprintkeymap"></a><a name="printkeymap"></a>CMFCKeyMapDiálogo::PrintKeyMap

Chamado pela estrutura quando um usuário clica no botão **Imprimir.**

```
virtual void PrintKeyMap();
```

### <a name="remarks"></a>Comentários

O `PrintKeyMap` método imprime o mapa-chave. Ele inicia um novo trabalho de impressão e, em seguida, chama repetidamente o [CMFCKeyMapDialog::OnPrintHeader](#onprintheader) e [CMFCKeyMapDiálogo::OnPrintItem](#onprintitem) métodos até que todos os mapeamentos principais sejam impressos.

## <a name="cmfckeymapdialogsetcolumnswidth"></a><a name="setcolumnswidth"></a>CMFCKeyMapDiálogo::ConjuntoColunasLargura

Chamado pela estrutura para definir a largura das colunas no controle de lista interna que suporta o controle de mapeamento do teclado.

```
virtual void SetColumnsWidth();
```

### <a name="remarks"></a>Comentários

Este método define as colunas do controle de lista interna para larguras padrão. Primeiro, a largura da coluna de teclas de atalho é calculada. Em seguida, um terço da largura restante é alocada na coluna de comando e os dois terços restantes são alocados na coluna de descrição.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes](../../mfc/reference/mfc-classes.md)<br/>
[Classe CKeyboardManager](../../mfc/reference/ckeyboardmanager-class.md)
