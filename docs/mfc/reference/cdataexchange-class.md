---
title: Classe CDataExchange
ms.date: 11/04/2016
f1_keywords:
- CDataExchange
- AFXWIN/CDataExchange
- AFXWIN/CDataExchange::CDataExchange
- AFXWIN/CDataExchange::Fail
- AFXWIN/CDataExchange::PrepareCtrl
- AFXWIN/CDataExchange::PrepareEditCtrl
- AFXWIN/CDataExchange::PrepareOleCtrl
- AFXWIN/CDataExchange::m_bSaveAndValidate
- AFXWIN/CDataExchange::m_pDlgWnd
helpviewer_keywords:
- CDataExchange [MFC], CDataExchange
- CDataExchange [MFC], Fail
- CDataExchange [MFC], PrepareCtrl
- CDataExchange [MFC], PrepareEditCtrl
- CDataExchange [MFC], PrepareOleCtrl
- CDataExchange [MFC], m_bSaveAndValidate
- CDataExchange [MFC], m_pDlgWnd
ms.assetid: 84ed6113-325d-493e-a75d-223f03a992b8
ms.openlocfilehash: 7d0a804294fa5da619bdab4184adf3e28c420506
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50509286"
---
# <a name="cdataexchange-class"></a>Classe CDataExchange

Dá suporte a troca de dados de caixa de diálogo (DDX) e as rotinas de validação (DDV) de dados de caixa de diálogo usadas pelas classes do Microsoft Foundation.

## <a name="syntax"></a>Sintaxe

```
class CDataExchange
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataExchange::CDataExchange](#cdataexchange)|Constrói um objeto `CDataExchange`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataExchange::Fail](#fail)|Chamado quando a validação falha. Redefine o foco para o controle anterior e lança uma exceção.|
|[CDataExchange::PrepareCtrl](#preparectrl)|Prepara o controle especificado para troca de dados ou de validação. Use para controles nonedit.|
|[CDataExchange::PrepareEditCtrl](#prepareeditctrl)|Prepara o controle de edição especificado para troca de dados ou de validação.|
|[CDataExchange::PrepareOleCtrl](#prepareolectrl)|Prepara o controle OLE especificado para troca de dados ou de validação. Use para controles nonedit.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataExchange::m_bSaveAndValidate](#m_bsaveandvalidate)|Sinalizador de direção de DDX e DDV.|
|[CDataExchange::m_pDlgWnd](#m_pdlgwnd)|Ocorre a caixa de diálogo ou janela em que os dados do exchange.|

## <a name="remarks"></a>Comentários

`CDataExchange` não tem uma classe base.

Use essa classe se você estiver escrevendo rotinas de troca de dados para tipos de dados personalizados ou controles, ou se você estiver escrevendo suas próprias rotinas de validação de dados. Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de observação técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [caixas de diálogo](../../mfc/dialog-boxes.md).

Um `CDataExchange` objeto fornece as informações de contexto necessárias para colocam DDX e DDV entrem. O sinalizador *m_bSaveAndValidate* é FALSE quando DDX é usado para preencher os valores iniciais dos controles de caixa de diálogo de membros de dados. O sinalizador *m_bSaveAndValidate* é verdadeiro quando DDX é usado para definir os valores atuais dos controles de caixa de diálogo em membros de dados e ao DDV é usado para validar os valores de dados. Se a validação de DDV falhar, o procedimento DDV exibirá uma caixa de mensagem explicando o erro de entrada. Em seguida, chamará o procedimento DDV `Fail` para redefinir o foco para o controle transgressor e lançar uma exceção para interromper o processo de validação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDataExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="cdataexchange"></a>  CDataExchange::CDataExchange

Chame essa função de membro para construir um `CDataExchange` objeto.

```
CDataExchange(
    CWnd* pDlgWnd,
    BOOL bSaveAndValidate);
```

### <a name="parameters"></a>Parâmetros

*pDlgWnd*<br/>
Um ponteiro para a janela pai que contém o controle. Normalmente, isso é um [CDialog](../../mfc/reference/cdialog-class.md)-objeto derivado.

*bSaveAndValidate*<br/>
Se for TRUE, esse objeto valida os dados, em seguida, grava os dados dos controles para os membros. Se for FALSE, esse objeto será mover dados de membros aos controles.

### <a name="remarks"></a>Comentários

Construir uma `CDataExchange` objeto por conta própria para armazenar informações adicionais no objeto de troca de dados para passar para a janela [CWnd::DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange) função de membro.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#70](../../mfc/codesnippet/cpp/cdataexchange-class_1.cpp)]

##  <a name="fail"></a>  CDataExchange::Fail

O framework chama essa função membro, quando uma operação de validação (DDV) de dados de caixa de diálogo falha.

```
void Fail();
```

### <a name="remarks"></a>Comentários

`Fail` Restaura o foco e a seleção para o controle cuja validação falhou (se houver um controle para restaurar). `Fail` em seguida, lança uma exceção do tipo [CUserException](../../mfc/reference/cuserexception-class.md) para interromper o processo de validação. A exceção faz com que uma caixa de mensagem explicando o erro a ser exibido. Depois que a validação de DDV falha, o usuário pode digitar novamente dados no controle incorreto.

Os implementadores das rotinas DDV personalizadas podem chamar `Fail` de suas rotinas quando uma validação falhar.

Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de observação técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).

##  <a name="m_bsaveandvalidate"></a>  CDataExchange::m_bSaveAndValidate

Esse sinalizador indica a direção de uma operação de troca (DDX) de dados de caixa de diálogo.

```
BOOL m_bSaveAndValidate;
```

### <a name="remarks"></a>Comentários

O sinalizador é diferente de zero se o `CDataExchange` objeto está sendo usado para mover dados dos controles de caixa de diálogo para membros de dados de classe de caixa de diálogo depois que o usuário edita os controles. O sinalizador for zero, se o objeto está sendo usado para inicializar os controles de caixa de diálogo de membros de dados de classe de caixa de diálogo.

O sinalizador também é diferente de zero durante a validação de dados de caixa de diálogo (DDV).

Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de observação técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).

##  <a name="m_pdlgwnd"></a>  CDataExchange::m_pDlgWnd

Contém um ponteiro para o [CWnd](../../mfc/reference/cwnd-class.md) objeto para a qual caixa de diálogo (DDX) de troca de dados ou de validação (DDV) está em andamento.

```
CWnd* m_pDlgWnd;
```

### <a name="remarks"></a>Comentários

Esse objeto é geralmente um [CDialog](../../mfc/reference/cdialog-class.md) objeto. Os implementadores das rotinas DDX ou DDV personalizadas podem usar esse ponteiro para obter acesso à caixa de diálogo janela que contém os controles estiverem operando em.

Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de observação técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).

##  <a name="preparectrl"></a>  CDataExchange::PrepareCtrl

O framework chama essa função de membro para preparar o controle especificado para a troca de dados de caixa de diálogo (DDX) e a validação (DDV).

```
HWND PrepareCtrl(int nIDC);
```

### <a name="parameters"></a>Parâmetros

*nIDC*<br/>
A ID do controle para estar preparado para DDX ou DDV.

### <a name="return-value"></a>Valor de retorno

O HWND do controle que está sendo preparado para DDX ou DDV.

### <a name="remarks"></a>Comentários

Use [PrepareEditCtrl](#prepareeditctrl) para controles de edição; use essa função de membro para todos os outros controles.

Preparação consiste em armazenar o HWND do controle a `CDataExchange` classe. A estrutura usa esse identificador para restaurar o foco para o controle anteriormente com foco em caso de falha DDX ou DDV.

Os implementadores das rotinas DDX ou DDV personalizadas devem chamar `PrepareCtrl` para todos os controles de edição não para os quais estão trocando dados por meio de DDX ou validação de dados por meio de DDV.

Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de observação técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).

##  <a name="prepareeditctrl"></a>  CDataExchange::PrepareEditCtrl

O framework chama essa função de membro para preparar o controle de edição especificado para a troca de dados de caixa de diálogo (DDX) e a validação (DDV).

```
HWND PrepareEditCtrl(int nIDC);
```

### <a name="parameters"></a>Parâmetros

*nIDC*<br/>
A ID do controle de edição para estar preparado para DDX ou DDV.

### <a name="return-value"></a>Valor de retorno

O HWND do controle de edição que está sendo preparado para DDX ou DDV.

### <a name="remarks"></a>Comentários

Use [PrepareCtrl](#preparectrl) em vez disso, para todos os controles de edição não.

Preparação consiste em duas coisas. Primeiro, `PrepareEditCtrl` armazena o HWND do controle a `CDataExchange` classe. A estrutura usa esse identificador para restaurar o foco para o controle anteriormente com foco em caso de falha DDX ou DDV. Segundo, `PrepareEditCtrl` define um sinalizador no `CDataExchange` classe para indicar que o controle cuja data está sendo trocada ou validado é um controle de edição.

Os implementadores das rotinas DDX ou DDV personalizadas devem chamar `PrepareEditCtrl` para todos os controles para os quais estão trocando dados por meio de DDX ou validação de dados por meio de DDV de editar.

Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de observação técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).

##  <a name="prepareolectrl"></a>  CDataExchange::PrepareOleCtrl

O framework chama essa função de membro para preparar o controle OLE especificado para a troca de dados de caixa de diálogo (DDX) e a validação (DDV).

```
COleControlSite* PrepareOleCtrl(int nIDC);
```

### <a name="parameters"></a>Parâmetros

*nIDC*<br/>
A ID do controle OLE para estar preparado para DDX ou DDV.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o site de controle OLE.

### <a name="remarks"></a>Comentários

Use [PrepareEditCtrl](#prepareeditctrl) em vez disso, para controles de edição ou [PrepareCtrl](#preparectrl) para todos os outros controles não são OLE.

Os implementadores das rotinas DDX ou DDV personalizadas devem chamar `PrepareOleCtrl` para todos os controles OLE para os quais estão trocando dados por meio de DDX ou validação de dados por meio de DDV.

Para obter mais informações sobre como escrever suas próprias rotinas DDX e DDV, consulte [26 de observação técnica](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral de DDX e DDV, consulte [troca de dados de caixa de diálogo e validação](../../mfc/dialog-data-exchange-and-validation.md) e [tópicos da caixa de diálogo](../../mfc/dialog-boxes.md).

## <a name="see-also"></a>Consulte também

[Exemplo MFC VIEWEX](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CWnd::DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange)<br/>
[CWnd::UpdateData](../../mfc/reference/cwnd-class.md#updatedata)

