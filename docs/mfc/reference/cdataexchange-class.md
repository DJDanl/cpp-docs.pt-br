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
ms.openlocfilehash: fd1bce7de7ac323dc3099ab4938306768eb95a35
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81754626"
---
# <a name="cdataexchange-class"></a>Classe CDataExchange

Suporta as rotinas de troca de dados de diálogo (DDX) e de validação de dados de diálogo (DDV) usadas pelas classes da Microsoft Foundation.

## <a name="syntax"></a>Sintaxe

```
class CDataExchange
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataExchange::CDataExchange](#cdataexchange)|Constrói um objeto `CDataExchange`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataExchange::Falha](#fail)|Chamado quando a validação falha. Redefine o foco para o controle anterior e lança uma exceção.|
|[CDataExchange::PrepareCtrl](#preparectrl)|Prepara o controle especificado para troca ou validação de dados. Use para controles não-editados.|
|[CDataExchange::PrepareEditCtrl](#prepareeditctrl)|Prepara o controle de edição especificado para troca ou validação de dados.|
|[CDataExchange::PrepareOleCtrl](#prepareolectrl)|Prepara o controle OLE especificado para troca ou validação de dados. Use para controles não-editados.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDataExchange::m_bSaveAndValidate](#m_bsaveandvalidate)|Bandeira para a direção de DDX e DDV.|
|[CDataExchange::m_pDlgWnd](#m_pdlgwnd)|A caixa de diálogo ou janela onde ocorre a troca de dados.|

## <a name="remarks"></a>Comentários

`CDataExchange`não tem uma classe base.

Use esta classe se você estiver escrevendo rotinas de troca de dados para tipos ou controles personalizados de dados ou se você estiver escrevendo suas próprias rotinas de validação de dados. Para obter mais informações sobre como escrever suas próprias rotinas de DDX e DDV, consulte [nota técnica 26](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral do DDX e do DDV, consulte [Troca de dados de diálogo e caixas de validação](../../mfc/dialog-data-exchange-and-validation.md) e [diálogo](../../mfc/dialog-boxes.md).

Um `CDataExchange` objeto fornece as informações de contexto necessárias para que o DDX e o DDV ocorram. O *m_bSaveAndValidate de* bandeira é FALSO quando o DDX é usado para preencher os valores iniciais dos controles de diálogo dos membros de dados. O *m_bSaveAndValidate* de bandeira é VERDADEIRO quando o DDX é usado para definir os valores atuais dos controles de diálogo em membros de dados e quando o DDV é usado para validar os valores de dados. Se a validação do DDV falhar, o procedimento DDV exibirá uma caixa de mensagem explicando o erro de entrada. O procedimento de DDV, então, chamará `Fail` para redefinir o foco para o controle ofensivo e lançar uma exceção para interromper o processo de validação.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CDataExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="cdataexchangecdataexchange"></a><a name="cdataexchange"></a>CDataExchange::CDataExchange

Chame esta função de `CDataExchange` membro para construir um objeto.

```
CDataExchange(
    CWnd* pDlgWnd,
    BOOL bSaveAndValidate);
```

### <a name="parameters"></a>Parâmetros

*pDlgWnd*<br/>
Um ponteiro para a janela pai que contém o controle. Normalmente este é um objeto derivado do [CDialog.](../../mfc/reference/cdialog-class.md)

*bSaveAndValidate*<br/>
Se TRUE, este objeto valida dados e, em seguida, grava dados dos controles para os membros. Se FALSO, este objeto moverá dados de membros para controles.

### <a name="remarks"></a>Comentários

Construa `CDataExchange` um objeto para armazenar informações extras no objeto de troca de dados para passar para a função de membro [cwnd::DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange) da sua janela.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCControlLadenDialog#70](../../mfc/codesnippet/cpp/cdataexchange-class_1.cpp)]

## <a name="cdataexchangefail"></a><a name="fail"></a>CDataExchange::Falha

O framework chama essa função de membro quando uma operação de validação de dados de diálogo (DDV) falha.

```cpp
void Fail();
```

### <a name="remarks"></a>Comentários

`Fail`restaura o foco e a seleção para o controle cuja validação falhou (se houver um controle para restaurar). `Fail`em seguida, lança uma exceção do tipo [CUserException](../../mfc/reference/cuserexception-class.md) para interromper o processo de validação. A exceção faz com que uma caixa de mensagem que explique o erro seja exibida. Após a falha na validação do DDV, o usuário pode reinserir dados no controle ofensivo.

Implementores de rotinas de `Fail` DDV personalizadas podem ligar de suas rotinas quando uma validação falha.

Para obter mais informações sobre como escrever suas próprias rotinas de DDX e DDV, consulte [nota técnica 26](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral do DDX e do DDV, consulte [Diálogo Data Exchange e Validation](../../mfc/dialog-data-exchange-and-validation.md) and Dialog Box [Topics](../../mfc/dialog-boxes.md).

## <a name="cdataexchangem_bsaveandvalidate"></a><a name="m_bsaveandvalidate"></a>CDataExchange::m_bSaveAndValidate

Este sinalizador indica a direção de uma operação de troca de dados de diálogo (DDX).

```
BOOL m_bSaveAndValidate;
```

### <a name="remarks"></a>Comentários

O sinalizador não é `CDataExchange` zero se o objeto estiver sendo usado para mover dados dos controles de diálogo para membros de dados da classe de diálogo após o usuário etificar os controles. O sinalizador é zero se o objeto estiver sendo usado para inicializar os controles de diálogo de membros de dados da classe diálogo.

O sinalizador também não é zero durante a validação de dados de diálogo (DDV).

Para obter mais informações sobre como escrever suas próprias rotinas de DDX e DDV, consulte [nota técnica 26](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral do DDX e do DDV, consulte [Diálogo Data Exchange e Validation](../../mfc/dialog-data-exchange-and-validation.md) and Dialog Box [Topics](../../mfc/dialog-boxes.md).

## <a name="cdataexchangem_pdlgwnd"></a><a name="m_pdlgwnd"></a>CDataExchange::m_pDlgWnd

Contém um ponteiro para o objeto [CWnd](../../mfc/reference/cwnd-class.md) para o qual a troca de dados de diálogo (DDX) ou validação (DDV) está ocorrendo.

```
CWnd* m_pDlgWnd;
```

### <a name="remarks"></a>Comentários

Este objeto geralmente é um objeto [CDialog.](../../mfc/reference/cdialog-class.md) Os implementores de rotinas personalizadas de DDX ou DDV podem usar este ponteiro para obter acesso à janela de diálogo que contém os controles em que estão operando.

Para obter mais informações sobre como escrever suas próprias rotinas de DDX e DDV, consulte [nota técnica 26](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral do DDX e do DDV, consulte [Diálogo Data Exchange e Validation](../../mfc/dialog-data-exchange-and-validation.md) and Dialog Box [Topics](../../mfc/dialog-boxes.md).

## <a name="cdataexchangepreparectrl"></a><a name="preparectrl"></a>CDataExchange::PrepareCtrl

O framework chama essa função de membro para preparar o controle especificado para troca de dados de diálogo (DDX) e validação (DDV).

```
HWND PrepareCtrl(int nIDC);
```

### <a name="parameters"></a>Parâmetros

*nIDC*<br/>
O ID do controle a ser preparado para DDX ou DDV.

### <a name="return-value"></a>Valor retornado

O HWND do controle que está sendo preparado para DDX ou DDV.

### <a name="remarks"></a>Comentários

Use [PrepareEditCtrl](#prepareeditctrl) em vez disso para editar controles; use esta função de membro para todos os outros controles.

A preparação consiste em armazenar o HWND `CDataExchange` do controle na classe. A estrutura usa esta alça para restaurar o foco para o controle previamente focado no caso de uma falha de DDX ou DDV.

Os implementadores das rotinas personalizadas de `PrepareCtrl` DDX ou DDV devem solicitar todos os controles não-editais para os quais eles estão trocando dados via DDX ou validando dados via DDV.

Para obter mais informações sobre como escrever suas próprias rotinas de DDX e DDV, consulte [nota técnica 26](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral do DDX e do DDV, consulte [Diálogo Data Exchange e Validation](../../mfc/dialog-data-exchange-and-validation.md) and Dialog Box [Topics](../../mfc/dialog-boxes.md).

## <a name="cdataexchangeprepareeditctrl"></a><a name="prepareeditctrl"></a>CDataExchange::PrepareEditCtrl

O framework chama essa função de membro para preparar o controle de edição especificado para troca de dados de diálogo (DDX) e validação (DDV).

```
HWND PrepareEditCtrl(int nIDC);
```

### <a name="parameters"></a>Parâmetros

*nIDC*<br/>
O ID do controle de edição a ser preparado para DDX ou DDV.

### <a name="return-value"></a>Valor retornado

O HWND do controle de edição sendo preparado para DDX ou DDV.

### <a name="remarks"></a>Comentários

Use [PrepareCtrl](#preparectrl) em vez disso para todos os controles não-edição.

A preparação consiste em duas coisas. Primeiro, `PrepareEditCtrl` armazena o HWND do `CDataExchange` controle na classe. A estrutura usa esta alça para restaurar o foco para o controle previamente focado no caso de uma falha de DDX ou DDV. Em `PrepareEditCtrl` segundo lugar, `CDataExchange` define uma bandeira na classe para indicar que o controle cujos dados estão sendo trocados ou validados é um controle de edição.

Os implementadores das rotinas personalizadas de `PrepareEditCtrl` DDX ou DDV devem solicitar todos os controles de edição para os quais eles estão trocando dados via DDX ou validando dados via DDV.

Para obter mais informações sobre como escrever suas próprias rotinas de DDX e DDV, consulte [nota técnica 26](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral do DDX e do DDV, consulte [Diálogo Data Exchange e Validation](../../mfc/dialog-data-exchange-and-validation.md) and Dialog Box [Topics](../../mfc/dialog-boxes.md).

## <a name="cdataexchangeprepareolectrl"></a><a name="prepareolectrl"></a>CDataExchange::PrepareOleCtrl

O framework chama essa função de membro para preparar o controle OLE especificado para troca de dados de diálogo (DDX) e validação (DDV).

```
COleControlSite* PrepareOleCtrl(int nIDC);
```

### <a name="parameters"></a>Parâmetros

*nIDC*<br/>
O ID do controle OLE a ser preparado para DDX ou DDV.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o local de controle oLE.

### <a name="remarks"></a>Comentários

Use [PrepareEditCtrl](#prepareeditctrl) em vez disso para editar controles ou [PrepareCtrl](#preparectrl) para todos os outros controles não-OLE.

Os implementadores das rotinas personalizadas de `PrepareOleCtrl` DDX ou DDV devem solicitar todos os controles OLE para os quais eles estão trocando dados via DDX ou validando dados via DDV.

Para obter mais informações sobre como escrever suas próprias rotinas de DDX e DDV, consulte [nota técnica 26](../../mfc/tn026-ddx-and-ddv-routines.md). Para obter uma visão geral do DDX e do DDV, consulte [Diálogo Data Exchange e Validation](../../mfc/dialog-data-exchange-and-validation.md) and Dialog Box [Topics](../../mfc/dialog-boxes.md).

## <a name="see-also"></a>Confira também

[MFC Amostra VIEWEX](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CWnd::DoDataExchange](../../mfc/reference/cwnd-class.md#dodataexchange)<br/>
[CWnd::UpdateData](../../mfc/reference/cwnd-class.md#updatedata)
