---
title: Páginas de propriedade (MFC)
ms.date: 11/04/2016
f1_keywords:
- vc.mfc.macros
helpviewer_keywords:
- property page data transfer functions in MFC
- property pages [MFC], global MFC functions
ms.assetid: 734f88bc-c776-4136-9b0e-f45c761a45c1
ms.openlocfilehash: e2f75044c7cfbc1f9d2af1d9bda5c108f9afa881
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57269208"
---
# <a name="property-pages-mfc"></a>Páginas de propriedade (MFC)

Páginas de propriedades exibem os valores atuais das propriedades de controle OLE específicos em uma interface gráfica e personalizável para exibir e editar, oferecendo suporte a um mecanismo de mapeamento de dados com base em troca de dados de caixa de diálogo (DDX).

Esse mecanismo de mapeamento de dados mapeia os controles de página de propriedade para as propriedades individuais de controle OLE. O valor da propriedade do controle reflete o status ou o conteúdo do controle de página de propriedades. O mapeamento entre propriedades e controles de página de propriedade especificado pelo **DDP _** chamadas de função na página de propriedades `DoDataExchange` função de membro. A seguir está uma lista dos **DDP _** funções que trocam dados inseridos usando a página de propriedades do seu controle:

### <a name="property-page-data-transfer"></a>Transferência de dados da página de propriedade

|||
|-|-|
|[DDP_CBIndex](#ddp_cbindex)|Vincula o índice da cadeia de caracteres selecionados em uma caixa de combinação com uma propriedade do controle.|
|[DDP_CBString](#ddp_cbstring)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade do controle. A cadeia de caracteres selecionada pode começar com as mesmas letras de como o valor da propriedade, mas não precisa corresponder a ele totalmente.|
|[DDP_CBStringExact](#ddp_cbstringexact)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com uma propriedade do controle. A cadeia de caracteres selecionada e o valor de cadeia de caracteres da propriedade devem corresponder exatamente.|
|[DDP_Check](#ddp_check)|Uma caixa de seleção na página de propriedades do controle com uma propriedade do controle de links.|
|[DDP_LBIndex](#ddp_lbindex)|Vincula o índice da cadeia de caracteres selecionados na caixa de listagem com uma propriedade do controle.|
|[DDP_LBString](#ddp_lbstring)|Vincula a cadeia de caracteres selecionada na caixa de listagem com uma propriedade do controle. A cadeia de caracteres selecionada pode começar com as mesmas letras de como o valor da propriedade, mas não precisa correspondê-la totalmente.|
|[DDP_LBStringExact](#ddp_lbstringexact)|Vincula a cadeia de caracteres selecionada na caixa de listagem com uma propriedade do controle. A cadeia de caracteres selecionada e o valor de cadeia de caracteres da propriedade devem corresponder exatamente.|
|[DDP_PostProcessing](#ddp_postprocessing)|Conclui a transferência de valores de propriedade de seu controle.|
|[DDP_Radio](#ddp_radio)|Links de um grupo de botões de opção na página de propriedades do controle com uma propriedade do controle.|
|[DDP_Text](#ddp_text)|Vincula um controle na página de propriedades do controle com uma propriedade do controle. Essa função manipula vários tipos diferentes de propriedades, tais como **duplas**, **curto**, BSTR, e **longo**.|

Para obter mais informações sobre o `DoDataExchange` páginas de propriedade e de função, consulte o artigo [controles ActiveX: Páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).

A seguir está uma lista de macros usadas para criar e gerenciar páginas de propriedades para um controle OLE:

### <a name="property-pages"></a>Páginas de propriedade

|||
|-|-|
|[BEGIN_PROPPAGEIDS](#begin_proppageids)|Inicia a lista de IDs de página de propriedade.|
|[END_PROPPAGEIDS](#end_proppageids)|Termina a lista de IDs de página de propriedade.|
|[PROPPAGEID](#proppageid)|Declara uma página de propriedades da classe do controle.|

##  <a name="ddp_cbindex"></a>  DDP_CBIndex

Chame essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de inteiro com o índice da seleção atual em uma caixa de combinação na página de propriedades.

```
void AFXAPI DDP_CBIndex(
    CDataExchange* pDX,
    int id,
    int& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID do recurso da caixa de combinação de caixa de controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle sejam trocadas com o controle de caixa de combinação especificado pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_CBIndex` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_cbstring"></a>  DDP_CBString

Chame essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres com a seleção atual em uma caixa de combinação na página de propriedades.

```
void AFXAPI DDP_CBString(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID do recurso da caixa de combinação de caixa de controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle a ser trocado com a cadeia de caracteres de caixa de combinação especificada pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_CBString` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_cbstringexact"></a>  DDP_CBStringExact

Chame essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres que corresponde exatamente a seleção atual em uma caixa de combinação na página de propriedades.

```
void AFXAPI DDP_CBStringExact(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID do recurso da caixa de combinação de caixa de controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle a ser trocado com a cadeia de caracteres de caixa de combinação especificada pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_CBStringExact` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_check"></a>  DDP_Check

Chame essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor da propriedade com o controle de caixa de seleção de página de propriedade associada.

```
void AFXAPI DDP_Check(
    CDataExchange* pDX,
    int id,
    int & member,
    LPCSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle de caixa de seleção associada com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle sejam trocadas com o controle de caixa de seleção especificado pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_Check` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_lbindex"></a>  DDP_LBIndex

Chame essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de inteiro com o índice da seleção atual em uma caixa de listagem na página de propriedades.

```
void AFXAPI DDP_LBIndex(
    CDataExchange* pDX,
    int id,
    int& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID do recurso da lista de caixa de controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle a ser trocado com a cadeia de caracteres de caixa de lista especificada pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_LBIndex` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_lbstring"></a>  DDP_LBString

Chame essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres com a seleção atual em uma caixa de listagem na página de propriedades.

```
void AFXAPI DDP_LBString(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID do recurso da lista de caixa de controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle a ser trocado com a cadeia de caracteres de caixa de lista especificada pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_LBString` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_lbstringexact"></a>  DDP_LBStringExact

Chame essa função em sua página de propriedades `DoDataExchange` função para sincronizar o valor de uma propriedade de cadeia de caracteres que corresponde exatamente a seleção atual em uma caixa de listagem na página de propriedades.

```
void AFXAPI DDP_LBStringExact(
    CDataExchange* pDX,
    int id,
    CString& member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID do recurso da lista de caixa de controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle a ser trocado com a cadeia de caracteres de caixa de lista especificada pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_LBStringExact` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_postprocessing"></a>  DDP_PostProcessing

Chame essa função em sua página de propriedades `DoDataExchange` função, para concluir a transferência de valores de propriedade da página de propriedade para o seu controle quando valores de propriedade estão sendo salvas.

```
void AFXAPI DDP_PostProcessing(CDataExchange * pDX);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada após a conclusão de todas as funções da troca de dados. Por exemplo:

[!code-cpp[NVC_MFCAxCtl#15](../../mfc/reference/codesnippet/cpp/property-pages-mfc_1.cpp)]

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_radio"></a>  DDP_Radio

Chame essa função em seu controle `DoPropExchange` função para sincronizar o valor da propriedade com o controle de botão de opção de página de propriedade associada.

```
void AFXAPI DDP_Radio(
    CDataExchange* pDX,
    int id,
    int & member,
    LPCTSTR pszPropName);
```

### <a name="parameters"></a>Parâmetros

*pDX*<br/>
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do rádio botão controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle sejam trocadas com o controle de botão de opção especificado pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_Radio` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="ddp_text"></a>  DDP_Text

Chame essa função em seu controle `DoDataExchange` função para sincronizar o valor da propriedade com o controle de página de propriedade associada.

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
Ponteiro para um `CDataExchange` objeto. A estrutura fornece esse objeto para estabelecer o contexto de troca de dados, incluindo sua direção.

*id*<br/>
A ID de recurso do controle associado com a propriedade do controle especificada pelo *pszPropName*.

*member*<br/>
A variável de membro associada ao controle de página de propriedade especificado por *identificação* e a propriedade especificada por *pszPropName*.

*pszPropName*<br/>
O nome de propriedade do controle sejam trocadas com o controle especificado pela propriedade *id*.

### <a name="remarks"></a>Comentários

Essa função deve ser chamada antes do correspondente `DDX_Text` chamada de função.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="begin_proppageids"></a>  BEGIN_PROPPAGEIDS

Inicia a definição de lista de seu controle de IDs de página de propriedade.

```
BEGIN_PROPPAGEIDS(class_name,  count)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe do controle para o qual propriedade páginas estão sendo especificadas.

*count*<br/>
O número de páginas de propriedade usado pela classe control.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, iniciar a lista de páginas de propriedade com a macro BEGIN_PROPPAGEIDS, em seguida, adicione entradas de macro para cada uma das suas páginas de propriedades e concluir a lista de páginas de propriedade com o END_PROPPAGEIDS macro.

Para obter mais informações sobre páginas de propriedades, consulte o artigo [controles ActiveX: Páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="end_proppageids"></a>  END_PROPPAGEIDS

Finaliza a definição de sua lista de ID de página de propriedade.

```
END_PROPPAGEIDS(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe do controle que possui a página de propriedades.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

##  <a name="proppageid"></a>  PROPPAGEID

Adiciona uma página de propriedades para uso pelo seu controle OLE.

```
PROPPAGEID(clsid)
```

### <a name="parameters"></a>Parâmetros

*clsid*<br/>
A ID de classe exclusivos de uma página de propriedades.

### <a name="remarks"></a>Comentários

Todas as macros PROPPAGEID devem ser colocadas entre as macros BEGIN_PROPPAGEIDS e END_PROPPAGEIDS no arquivo de implementação do seu controle.

### <a name="requirements"></a>Requisitos

  **Header** afxctl.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
