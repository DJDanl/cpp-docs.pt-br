---
title: Páginas de propriedade (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- property page data transfer functions in MFC
- property pages [MFC], global MFC functions
ms.assetid: 734f88bc-c776-4136-9b0e-f45c761a45c1
ms.openlocfilehash: 1064cd99d1820ae8865fa632c3097441172c78c4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372992"
---
# <a name="property-pages-mfc"></a>Páginas de propriedade (MFC)

Páginas de propriedade exibem os valores atuais de propriedades específicas de controle OLE em uma interface gráfica personalizável para visualização e edição, suportando um mecanismo de mapeamento de dados baseado na troca de dados de diálogo (DDX).

Este mecanismo de mapeamento de dados mapeia os controles da página de propriedade para as propriedades individuais do controle OLE. O valor da propriedade de controle reflete o status ou o conteúdo do controle da página de propriedade. O mapeamento entre controles de página de **DDP_** propriedade e propriedades é `DoDataExchange` especificado por DDP_ chamadas de função na função membro da página de propriedade. A seguir está uma lista de **funções DDP_** que trocam dados inseridos usando a página de propriedade do seu controle:

### <a name="property-page-data-transfer"></a>Transferência de dados da página de propriedade

|||
|-|-|
|[DDP_CBIndex](#ddp_cbindex)|Vincula o índice da seqüência selecionada em uma caixa de combinação com a propriedade de um controle.|
|[DDP_CBString](#ddp_cbstring)|Vincula a seqüência selecionada em uma caixa de combinação com a propriedade de um controle. A seqüência selecionada pode começar com as mesmas letras que o valor da propriedade, mas não precisa igualá-la totalmente.|
|[DDP_CBStringExact](#ddp_cbstringexact)|Vincula a seqüência selecionada em uma caixa de combinação com a propriedade de um controle. A seqüência selecionada e o valor da seqüência da propriedade devem corresponder exatamente.|
|[DDP_Check](#ddp_check)|Vincula uma caixa de seleção na página de propriedade do controle com a propriedade de um controle.|
|[DDP_LBIndex](#ddp_lbindex)|Vincula o índice da seqüência selecionada em uma caixa de lista com a propriedade de um controle.|
|[DDP_LBString](#ddp_lbstring)|Vincula a seqüência selecionada em uma caixa de lista com a propriedade de um controle. A seqüência selecionada pode começar com as mesmas letras que o valor da propriedade, mas não precisa corresponder totalmente.|
|[DDP_LBStringExact](#ddp_lbstringexact)|Vincula a seqüência selecionada em uma caixa de lista com a propriedade de um controle. A seqüência selecionada e o valor da seqüência da propriedade devem corresponder exatamente.|
|[DDP_PostProcessing](#ddp_postprocessing)|Termina a transferência de valores de propriedade do seu controle.|
|[DDP_Radio](#ddp_radio)|Vincula um grupo de botão de rádio na página de propriedade do controle com a propriedade de um controle.|
|[DDP_Text](#ddp_text)|Vincula um controle na página de propriedade do controle com a propriedade de um controle. Esta função lida com vários tipos diferentes de propriedades, como **duplo,** **curto,** BSTR e **longo**.|

Para obter mais `DoDataExchange` informações sobre as páginas de função e propriedade, consulte o artigo [ActiveX Controls: Property Pages](../../mfc/mfc-activex-controls-property-pages.md).

A seguir está uma lista de macros usadas para criar e gerenciar páginas de propriedade para um controle OLE:

### <a name="property-pages"></a>Páginas de propriedade

|||
|-|-|
|[BEGIN_PROPPAGEIDS](#begin_proppageids)|Começa a lista de IDs da página de propriedade.|
|[END_PROPPAGEIDS](#end_proppageids)|Termina a lista de IDs da página de propriedade.|
|[PROPPAGEID](#proppageid)|Declara uma página de propriedade da classe de controle.|

## <a name="ddp_cbindex"></a><a name="ddp_cbindex"></a>DDP_CBIndex

Chame essa função na função `DoDataExchange` da página de propriedade para sincronizar o valor de uma propriedade inteira com o índice da seleção atual em uma caixa de combinação na página da propriedade.

```
void AFXAPI DDP_CBIndex(
    CDataExchange* pDX,
    int id,
    int& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle da caixa de combinação associado à propriedade de controle especificada por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com o controle da caixa de combinação especificado por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_CBIndex` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_cbstring"></a><a name="ddp_cbstring"></a>DDP_CBString

Chame essa função na função `DoDataExchange` da página de propriedade para sincronizar o valor de uma propriedade de string com a seleção atual em uma caixa de combinação na página da propriedade.

```
void AFXAPI DDP_CBString(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle da caixa de combinação associado à propriedade de controle especificada por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com a seqüência de caixa de combinação especificada por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_CBString` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_cbstringexact"></a><a name="ddp_cbstringexact"></a>DDP_CBStringExact

Chame essa função na função `DoDataExchange` da página de propriedade para sincronizar o valor de uma propriedade de string que corresponde exatamente à seleção atual em uma caixa de combinação na página da propriedade.

```
void AFXAPI DDP_CBStringExact(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle da caixa de combinação associado à propriedade de controle especificada por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com a seqüência de caixa de combinação especificada por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_CBStringExact` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_check"></a><a name="ddp_check"></a>DDP_Check

Chame essa função na função `DoDataExchange` da página de propriedade para sincronizar o valor da propriedade com o controle da caixa de seleção da página de propriedade associada.

```
void AFXAPI DDP_Check(
    CDataExchange* pDX,
    int id,
    int & member,
    LPCSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle da caixa de seleção associado à propriedade de controle especificada por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com o controle da caixa de seleção especificado por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_Check` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_lbindex"></a><a name="ddp_lbindex"></a>DDP_LBIndex

Chame essa função na função `DoDataExchange` da página de propriedade para sincronizar o valor de uma propriedade inteira com o índice da seleção atual em uma caixa de lista na página da propriedade.

```
void AFXAPI DDP_LBIndex(
    CDataExchange* pDX,
    int id,
    int& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle de caixa de lista associado à propriedade de controle especificada por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com a seqüência de caixa de lista especificada por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_LBIndex` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_lbstring"></a><a name="ddp_lbstring"></a>DDP_LBString

Chame essa função na função `DoDataExchange` da página de propriedade para sincronizar o valor de uma propriedade de string com a seleção atual em uma caixa de lista na página da propriedade.

```
void AFXAPI DDP_LBString(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle de caixa de lista associado à propriedade de controle especificada por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com a seqüência de caixa de lista especificada por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_LBString` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_lbstringexact"></a><a name="ddp_lbstringexact"></a>DDP_LBStringExact

Chame essa função na função `DoDataExchange` da página de propriedade para sincronizar o valor de uma propriedade de string que corresponde exatamente à seleção atual em uma caixa de lista na página da propriedade.

```
void AFXAPI DDP_LBStringExact(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle de caixa de lista associado à propriedade de controle especificada por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com a seqüência de caixa de lista especificada por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_LBStringExact` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_postprocessing"></a><a name="ddp_postprocessing"></a>DDP_PostProcessing

Chame essa função na função `DoDataExchange` da página de propriedade, para concluir a transferência de valores de propriedade da página de propriedade para o seu controle quando os valores da propriedade estiverem sendo salvos.

```
void AFXAPI DDP_PostProcessing(CDataExchange * pDX);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

### <a name="remarks"></a>Comentários

Esta função deve ser chamada depois que todas as funções de troca de dados forem concluídas. Por exemplo:

[!code-cpp[NVC_MFCAxCtl#15](../../mfc/reference/codesnippet/cpp/property-pages-mfc_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_radio"></a><a name="ddp_radio"></a>DDP_Radio

Chame esta função na `DoPropExchange` função do controle para sincronizar o valor da propriedade com o controle do botão de rádio da página de propriedade associada.

```
void AFXAPI DDP_Radio(
    CDataExchange* pDX,
    int id,
    int & member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle do botão de rádio associado à propriedade de controle especificado por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com o controle do botão de rádio especificado por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_Radio` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="ddp_text"></a><a name="ddp_text"></a>DDP_Text

Chame essa função na `DoDataExchange` função do seu controle para sincronizar o valor da propriedade com o controle da página de propriedade associada.

```
void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    BYTE & member,
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    int & member,
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    UINT & member,
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    long & member,
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    DWORD & member,
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    float & member,
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    double & member,
    LPCTSTR pszPropName);

void AFXAPI DDP_Text(
    CDataExchange* pDX,
    int id,
    CString & member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para `CDataExchange` um objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
O ID de recurso do controle associado à propriedade de controle especificado por *pszPropName*.

*Membro*<br/>
A variável membro associada ao controle da página de propriedade especificada por *id* e a propriedade especificada por *pszPropName*.

*Pszpropname*<br/>
O nome da propriedade de propriedade de controle a ser trocado com o controle especificado por *id*.

### <a name="remarks"></a>Comentários

Esta função deve ser `DDX_Text` chamada antes da chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="begin_proppageids"></a><a name="begin_proppageids"></a>Begin_proppageids

Começa a definição da lista de IDs da página de propriedade do seu controle.

```
BEGIN_PROPPAGEIDS(class_name,  count)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle para a qual as páginas de propriedade estão sendo especificadas.

*contagem*<br/>
O número de páginas de propriedade usadas pela classe de controle.

### <a name="remarks"></a>Comentários

No arquivo de implementação (.cpp) que define as funções do membro para sua classe, inicie a lista de páginas de propriedade com a macro BEGIN_PROPPAGEIDS, adicione entradas de macro para cada uma de suas páginas de propriedade e complete a lista de páginas de propriedade com a END_PROPPAGEIDS macro.

Para obter mais informações sobre páginas de propriedade, consulte o artigo [ActiveX Controls: Property Pages](../../mfc/mfc-activex-controls-property-pages.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="end_proppageids"></a><a name="end_proppageids"></a>End_proppageids

Termina a definição da sua lista de ID da página de propriedade.

```
END_PROPPAGEIDS(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle que possui a página de propriedade.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="proppageid"></a><a name="proppageid"></a>PROPPAGEID

Adiciona uma página de propriedade para uso pelo controle OLE.

```
PROPPAGEID(clsid)
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
A identificação de classe única de uma página de propriedade.

### <a name="remarks"></a>Comentários

Todas as macros PROPPAGEID devem ser colocadas entre as macros BEGIN_PROPPAGEIDS e END_PROPPAGEIDS no arquivo de implementação do seu controle.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
