---
title: Páginas de propriedade (MFC)
ms.date: 11/04/2016
helpviewer_keywords:
- property page data transfer functions in MFC
- property pages [MFC], global MFC functions
ms.assetid: 734f88bc-c776-4136-9b0e-f45c761a45c1
ms.openlocfilehash: 9a04395aec8c2eb968e5cefaf410643a1ce03e32
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843580"
---
# <a name="property-pages-mfc"></a>Páginas de propriedade (MFC)

As páginas de propriedades exibem os valores atuais de propriedades de controle OLE específicas em uma interface gráfica personalizável para exibição e edição, dando suporte a um mecanismo de mapeamento de dados baseado na troca de dados de caixa de diálogo (campo DDX).

Esse mecanismo de mapeamento de dados mapeia controles de página de propriedades para as propriedades individuais do controle OLE. O valor da propriedade Control reflete o status ou o conteúdo do controle da página de propriedades. O mapeamento entre controles de página de propriedades e propriedades é especificado por **DDP_** chamadas de função na função de membro da página de propriedades `DoDataExchange` . Veja a seguir uma lista de **DDP_** funções que trocam dados inseridas usando a página de propriedades do seu controle:

### <a name="property-page-data-transfer"></a>Transferência de Dados de página de propriedades

|Nome|Descrição|
|-|-|
|[DDP_CBIndex](#ddp_cbindex)|Vincula o índice da cadeia de caracteres selecionada em uma caixa de combinação com a propriedade de um controle.|
|[DDP_CBString](#ddp_cbstring)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com a propriedade de um controle. A cadeia de caracteres selecionada pode começar com as mesmas letras que o valor da propriedade, mas não precisa fazer a correspondência completa.|
|[DDP_CBStringExact](#ddp_cbstringexact)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com a propriedade de um controle. A cadeia de caracteres selecionada e o valor da cadeia de caracteres da propriedade devem corresponder exatamente.|
|[DDP_Check](#ddp_check)|Vincula uma caixa de seleção na página de propriedades do controle com a propriedade de um controle.|
|[DDP_LBIndex](#ddp_lbindex)|Vincula o índice da cadeia de caracteres selecionada em uma caixa de listagem com a propriedade de um controle.|
|[DDP_LBString](#ddp_lbstring)|Vincula a cadeia de caracteres selecionada em uma caixa de listagem com a propriedade de um controle. A cadeia de caracteres selecionada pode começar com as mesmas letras do valor da propriedade, mas não precisa fazer a correspondência completa.|
|[DDP_LBStringExact](#ddp_lbstringexact)|Vincula a cadeia de caracteres selecionada em uma caixa de listagem com a propriedade de um controle. A cadeia de caracteres selecionada e o valor da cadeia de caracteres da propriedade devem corresponder exatamente.|
|[DDP_PostProcessing](#ddp_postprocessing)|Conclui a transferência de valores de Propriedade do seu controle.|
|[DDP_Radio](#ddp_radio)|Vincula um grupo de botões de opção na página de propriedades do controle com a propriedade de um controle.|
|[DDP_Text](#ddp_text)|Vincula um controle na página de propriedades do controle com a propriedade de um controle. Essa função manipula vários tipos diferentes de propriedades, como **`double`** , **`short`** , BSTR e **`long`** .|

Para obter mais informações sobre as `DoDataExchange` páginas de funções e propriedades, consulte o artigo [controles ActiveX: páginas de propriedades](../../mfc/mfc-activex-controls-property-pages.md).

Veja a seguir uma lista de macros usadas para criar e gerenciar páginas de propriedades para um controle OLE:

### <a name="property-pages"></a>Páginas de propriedade

|Nome|Descrição|
|-|-|
|[BEGIN_PROPPAGEIDS](#begin_proppageids)|Inicia a lista de IDs de página de propriedades.|
|[END_PROPPAGEIDS](#end_proppageids)|Encerra a lista de IDs de página de propriedades.|
|[PROPPAGEID](#proppageid)|Declara uma página de propriedades da classe Control.|

## <a name="ddp_cbindex"></a><a name="ddp_cbindex"></a> DDP_CBIndex

Chame essa função na função da página de propriedades `DoDataExchange` para sincronizar o valor de uma propriedade de inteiro com o índice da seleção atual em uma caixa de combinação na página de propriedades.

```cpp
void AFXAPI DDP_CBIndex(
    CDataExchange* pDX,
    int id,
    int& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de caixa de combinação associada à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pelo controle de caixa de combinação especificado por *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_CBIndex` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_cbstring"></a><a name="ddp_cbstring"></a> DDP_CBString

Chame essa função na função da página de propriedades `DoDataExchange` para sincronizar o valor de uma propriedade de cadeia de caracteres com a seleção atual em uma caixa de combinação na página de propriedades.

```cpp
void AFXAPI DDP_CBString(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de caixa de combinação associada à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pela cadeia de caracteres da caixa de combinação especificada pela *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_CBString` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_cbstringexact"></a><a name="ddp_cbstringexact"></a> DDP_CBStringExact

Chame essa função na função da página de propriedades `DoDataExchange` para sincronizar o valor de uma propriedade de cadeia de caracteres que corresponda exatamente à seleção atual em uma caixa de combinação na página de propriedades.

```cpp
void AFXAPI DDP_CBStringExact(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de caixa de combinação associada à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pela cadeia de caracteres da caixa de combinação especificada pela *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_CBStringExact` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_check"></a><a name="ddp_check"></a> DDP_Check

Chame essa função na função da página de propriedades `DoDataExchange` para sincronizar o valor da propriedade com o controle caixa de seleção da página de propriedades associada.

```cpp
void AFXAPI DDP_Check(
    CDataExchange* pDX,
    int id,
    int & member,
    LPCSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID do recurso do controle caixa de seleção associada à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pelo controle da caixa de seleção especificado pela *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_Check` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_lbindex"></a><a name="ddp_lbindex"></a> DDP_LBIndex

Chame essa função na função da página de propriedades `DoDataExchange` para sincronizar o valor de uma propriedade de inteiro com o índice da seleção atual em uma caixa de listagem na página de propriedades.

```cpp
void AFXAPI DDP_LBIndex(
    CDataExchange* pDX,
    int id,
    int& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de caixa de listagem associada à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pela cadeia de caracteres da caixa de listagem especificada pela *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_LBIndex` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_lbstring"></a><a name="ddp_lbstring"></a> DDP_LBString

Chame essa função na função da página de propriedades `DoDataExchange` para sincronizar o valor de uma propriedade de cadeia de caracteres com a seleção atual em uma caixa de listagem na página de propriedades.

```cpp
void AFXAPI DDP_LBString(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de caixa de listagem associada à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pela cadeia de caracteres da caixa de listagem especificada pela *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_LBString` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_lbstringexact"></a><a name="ddp_lbstringexact"></a> DDP_LBStringExact

Chame essa função na função da página de propriedades `DoDataExchange` para sincronizar o valor de uma propriedade de cadeia de caracteres que corresponda exatamente à seleção atual em uma caixa de listagem na página de propriedades.

```cpp
void AFXAPI DDP_LBStringExact(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de caixa de listagem associada à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pela cadeia de caracteres da caixa de listagem especificada pela *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_LBStringExact` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_postprocessing"></a><a name="ddp_postprocessing"></a> DDP_PostProcessing

Chame essa função na função da página de propriedades para `DoDataExchange` concluir a transferência de valores de propriedade da página de propriedades para seu controle quando os valores de propriedade estiverem sendo salvos.

```cpp
void AFXAPI DDP_PostProcessing(CDataExchange * pDX);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada após a conclusão de todas as funções de troca de dados. Por exemplo:

[!code-cpp[NVC_MFCAxCtl#15](../../mfc/reference/codesnippet/cpp/property-pages-mfc_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_radio"></a><a name="ddp_radio"></a> DDP_Radio

Chame essa função na função do controle `DoPropExchange` para sincronizar o valor da propriedade com o controle de botão de opção da página de propriedades associada.

```cpp
void AFXAPI DDP_Radio(
    CDataExchange* pDX,
    int id,
    int & member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de botão de opção associado à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pelo controle de botão de opção especificado por *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_Radio` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="ddp_text"></a><a name="ddp_text"></a> DDP_Text

Chame essa função na função do controle `DoDataExchange` para sincronizar o valor da propriedade com o controle de página de propriedade associado.

```cpp
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

### <a name="parameters"></a>parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto da troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle associado à propriedade de controle especificada por *pszPropName*.

*associado*<br/>
A variável de membro associada ao controle de página de propriedades especificado pela *ID* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome da propriedade da propriedade de controle a ser trocada pelo controle especificado por *ID*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes da `DDX_Text` chamada de função correspondente.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="begin_proppageids"></a><a name="begin_proppageids"></a> BEGIN_PROPPAGEIDS

Inicia a definição da lista de IDs de página de propriedades do seu controle.

```
BEGIN_PROPPAGEIDS(class_name,  count)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle para a qual as páginas de propriedades estão sendo especificadas.

*contagem*<br/>
O número de páginas de propriedades usadas pela classe Control.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para sua classe, inicie a lista de páginas de propriedades com a macro BEGIN_PROPPAGEIDS e, em seguida, adicione entradas de macro para cada uma das páginas de propriedades e preencha a lista de páginas de propriedades com a macro END_PROPPAGEIDS.

Para obter mais informações sobre páginas de propriedades, consulte o artigo [controles ActiveX: páginas de propriedades](../../mfc/mfc-activex-controls-property-pages.md).

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="end_proppageids"></a><a name="end_proppageids"></a> END_PROPPAGEIDS

Termina a definição da sua lista de IDs de página de propriedades.

```
END_PROPPAGEIDS(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle que possui a página de propriedades.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="proppageid"></a><a name="proppageid"></a> PROPPAGEID

Adiciona uma página de propriedades para uso pelo seu controle OLE.

```
PROPPAGEID(clsid)
```

### <a name="parameters"></a>parâmetros

*clsid*<br/>
A ID de classe exclusiva de uma página de propriedades.

### <a name="remarks"></a>Comentários

Todas as macros PROPPAGEID devem ser colocadas entre as macros BEGIN_PROPPAGEIDS e END_PROPPAGEIDS no arquivo de implementação do seu controle.

### <a name="requirements"></a>Requisitos

  **Cabeçalho** afxctl. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
