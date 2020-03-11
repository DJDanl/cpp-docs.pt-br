---
title: Classe CPropExchange
ms.date: 11/04/2016
f1_keywords:
- CPropExchange
- AFXCTL/CPropExchange
- AFXCTL/CPropExchange::ExchangeBlobProp
- AFXCTL/CPropExchange::ExchangeFontProp
- AFXCTL/CPropExchange::ExchangePersistentProp
- AFXCTL/CPropExchange::ExchangeProp
- AFXCTL/CPropExchange::ExchangeVersion
- AFXCTL/CPropExchange::GetVersion
- AFXCTL/CPropExchange::IsAsynchronous
- AFXCTL/CPropExchange::IsLoading
helpviewer_keywords:
- CPropExchange [MFC], ExchangeBlobProp
- CPropExchange [MFC], ExchangeFontProp
- CPropExchange [MFC], ExchangePersistentProp
- CPropExchange [MFC], ExchangeProp
- CPropExchange [MFC], ExchangeVersion
- CPropExchange [MFC], GetVersion
- CPropExchange [MFC], IsAsynchronous
- CPropExchange [MFC], IsLoading
ms.assetid: ed872180-e770-4942-892a-92139d501fab
ms.openlocfilehash: e9ad7c363f2580200af20baeb0acd7a93c1f603b
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78871765"
---
# <a name="cpropexchange-class"></a>Classe CPropExchange

Dá suporte à implementação de persistência para seus controles OLE.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CPropExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[CPropExchange::ExchangeBlobProp](#exchangeblobprop)|Troca uma propriedade BLOB (objeto binário grande).|
|[CPropExchange::ExchangeFontProp](#exchangefontprop)|Troca uma propriedade de fonte.|
|[CPropExchange::ExchangePersistentProp](#exchangepersistentprop)|Troca uma propriedade entre um controle e um arquivo.|
|[CPropExchange::ExchangeProp](#exchangeprop)|Troca propriedades de qualquer tipo interno.|
|[CPropExchange::ExchangeVersion](#exchangeversion)|Troca o número de versão de um controle OLE.|
|[CPropExchange:: GetVersion](#getversion)|Recupera o número de versão de um controle OLE.|
|[CPropExchange:: IsAsynchronous](#isasynchronous)|Determina se as trocas de propriedades são feitas de forma assíncrona.|
|[CPropExchange:: isuploading](#isloading)|Indica se as propriedades estão sendo carregadas no controle ou salvas dela.|

## <a name="remarks"></a>Comentários

`CPropExchange` não tem uma classe base.

Estabelece o contexto e a direção de uma troca de propriedade.

A persistência é a troca das informações de estado do controle, geralmente representadas por suas propriedades, entre o próprio controle e um meio.

A estrutura constrói um objeto derivado de `CPropExchange` quando é notificado de que as propriedades de um controle OLE devem ser carregadas ou armazenadas no armazenamento persistente.

A estrutura passa um ponteiro para esse `CPropExchange` objeto para a função `DoPropExchange` do seu controle. Se você usou um assistente para criar os arquivos iniciais para seu controle, a função de `DoPropExchange` do controle chama `COleControl::DoPropExchange`. A versão de classe base troca as propriedades de ações do controle; você modifica a versão da classe derivada para as propriedades do Exchange que você adicionou ao seu controle.

`CPropExchange` pode ser usado para serializar as propriedades de um controle ou inicializar as propriedades de um controle após a carga ou a criação de um controle. As funções de membro `ExchangeProp` e `ExchangeFontProp` de `CPropExchange` são capazes de armazenar propriedades e carregá-las de diferentes mídias.

Para obter mais informações sobre como usar `CPropExchange`, consulte o artigo [controles ActiveX do MFC: páginas de propriedades](../../mfc/mfc-activex-controls-property-pages.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CPropExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

##  <a name="exchangeblobprop"></a>CPropExchange::ExchangeBlobProp

Serializa uma propriedade que armazena dados BLOB (objeto binário grande).

```
virtual BOOL ExchangeBlobProp(
    LPCTSTR pszPropName,
    HGLOBAL* phBlob,
    HGLOBAL hBlobDefault = NULL) = 0;
```

### <a name="parameters"></a>parâmetros

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*phBlob*<br/>
Ponteiro para uma variável que aponta para onde a propriedade é armazenada (a variável é normalmente um membro de sua classe).

*hBlobDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou gravado em, conforme apropriado, a variável referenciada por *phBlob*. Se *hBlobDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor será usado se, por qualquer motivo, a serialização do controle falhar.

As funções `CArchivePropExchange::ExchangeBlobProp`, `CResetPropExchange::ExchangeBlobProp`e `CPropsetPropExchange::ExchangeBlobProp` substituem essa função virtual pura.

##  <a name="exchangefontprop"></a>CPropExchange::ExchangeFontProp

Troca uma propriedade de fonte entre um meio de armazenamento e o controle.

```
virtual BOOL ExchangeFontProp(
    LPCTSTR pszPropName,
    CFontHolder& font,
    const FONTDESC* pFontDesc,
    LPFONTDISP pFontDispAmbient) = 0;
```

### <a name="parameters"></a>parâmetros

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*la*<br/>
Uma referência a um objeto [CFontHolder](../../mfc/reference/cfontholder-class.md) que contém a propriedade Font.

*pFontDesc*<br/>
Um ponteiro para uma estrutura [FONTDESC](/windows/win32/api/olectl/ns-olectl-fontdesc) que contém valores para inicializar o estado padrão da propriedade Font quando *pFontDispAmbient* é nulo.

*pFontDispAmbient*<br/>
Um ponteiro para a interface de `IFontDisp` de uma fonte a ser usada para inicializar o estado padrão da propriedade Font.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Se a propriedade Font estiver sendo carregada da mídia para o controle, as características da fonte serão recuperadas do meio e o objeto `CFontHolder` referenciado pela *fonte* será inicializado com elas. Se a propriedade Font estiver sendo armazenada, as características no objeto Font serão gravadas na mídia.

As funções `CArchivePropExchange::ExchangeFontProp`, `CResetPropExchange::ExchangeFontProp`e `CPropsetPropExchange::ExchangeFontProp` substituem essa função virtual pura.

##  <a name="exchangepersistentprop"></a>CPropExchange::ExchangePersistentProp

Troca uma propriedade entre o controle e um arquivo.

```
virtual BOOL ExchangePersistentProp(
    LPCTSTR pszPropName,
    LPUNKNOWN* ppUnk,
    REFIID iid,
    LPUNKNOWN pUnkDefault) = 0;
```

### <a name="parameters"></a>parâmetros

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*ppUnk*<br/>
Um ponteiro para uma variável que contém um ponteiro para a interface de `IUnknown` da propriedade (essa variável normalmente é um membro de sua classe).

*IID*<br/>
ID da interface na propriedade que o controle usará.

*pUnkDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Se a propriedade estiver sendo carregada do arquivo para o controle, a propriedade será criada e inicializada a partir do arquivo. Se a propriedade estiver sendo armazenada, seu valor será gravado no arquivo.

As funções `CArchivePropExchange::ExchangePersistentProp`, `CResetPropExchange::ExchangePersistentProp`e `CPropsetPropExchange::ExchangePersistentProp` substituem essa função virtual pura.

##  <a name="exchangeprop"></a>CPropExchange::ExchangeProp

Troca uma propriedade entre um meio de armazenamento e o controle.

```
virtual BOOL ExchangeProp(
    LPCTSTR pszPropName,
    VARTYPE vtProp,
    void* pvProp,
    const void* pvDefault = NULL) = 0 ;
```

### <a name="parameters"></a>parâmetros

*pszPropName*<br/>
O nome da propriedade que está sendo trocada.

*vtProp*<br/>
Um símbolo que especifica o tipo da propriedade que está sendo trocada. Os valores possíveis são:

|Símbolo|Tipo de propriedade|
|------------|-------------------|
|VT_I2|**short**|
|VT_I4|**long**|
|VT_BOOL|**BOOL**|
|VT_BSTR|`CString`|
|VT_CY|**CY**|
|VT_R4|**float**|
|VT_R8|**double**|

*pvProp*<br/>
Um ponteiro para o valor da propriedade.

*pvDefault*<br/>
Ponteiro para um valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Se a propriedade estiver sendo carregada da mídia para o controle, o valor da propriedade será recuperado do meio e armazenado no objeto apontado por *pvProp*. Se a propriedade estiver sendo armazenada no meio, o valor do objeto apontado por *pvProp* será gravado na mídia.

As funções `CArchivePropExchange::ExchangeProp`, `CResetPropExchange::ExchangeProp`e `CPropsetPropExchange::ExchangeProp` substituem essa função virtual pura.

##  <a name="exchangeversion"></a>CPropExchange::ExchangeVersion

Chamado pelo Framework para lidar com a persistência de um número de versão.

```
virtual BOOL ExchangeVersion(
    DWORD& dwVersionLoaded,
    DWORD dwVersionDefault,
    BOOL bConvert);
```

### <a name="parameters"></a>parâmetros

*dwVersionLoaded*<br/>
A referência a uma variável em que o número de versão dos dados persistentes que estão sendo carregados será armazenada.

*dwVersionDefault*<br/>
O número da versão atual do controle.

*bConvert*<br/>
Indica se os dados persistentes devem ser convertidos na versão atual ou se devem ser mantidos na mesma versão que foi carregada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se a função for bem-sucedida; caso contrário, 0.

##  <a name="getversion"></a>CPropExchange:: GetVersion

Chame essa função para recuperar o número de versão do controle.

```
DWORD GetVersion();
```

### <a name="return-value"></a>Valor retornado

O número de versão do controle.

##  <a name="isasynchronous"></a>CPropExchange:: IsAsynchronous

Determina se as trocas de propriedades são feitas de forma assíncrona.

```
BOOL IsAsynchronous();
```

### <a name="return-value"></a>Valor retornado

Retornará TRUE se as propriedades forem trocadas de forma assíncrona, caso contrário, FALSE.

##  <a name="isloading"></a>CPropExchange:: isuploading

Chame essa função para determinar se as propriedades estão sendo carregadas no controle ou salvas dela.

```
BOOL IsLoading();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se as propriedades estiverem sendo carregadas; caso contrário, 0.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[COleControl::D oPropExchange](../../mfc/reference/colecontrol-class.md#dopropexchange)
