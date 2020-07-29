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
ms.openlocfilehash: 09fb1bd34f3b5eadb78d8f9081450c042fe22f9e
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87226861"
---
# <a name="cpropexchange-class"></a>Classe CPropExchange

Dá suporte à implementação de persistência para seus controles OLE.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CPropExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
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

`CPropExchange`Não tem uma classe base.

Estabelece o contexto e a direção de uma troca de propriedade.

A persistência é a troca das informações de estado do controle, geralmente representadas por suas propriedades, entre o próprio controle e um meio.

A estrutura constrói um objeto derivado de `CPropExchange` quando é notificado que as propriedades de um controle OLE devem ser carregadas ou armazenadas no armazenamento persistente.

A estrutura passa um ponteiro para esse `CPropExchange` objeto para a função do controle `DoPropExchange` . Se você usou um assistente para criar os arquivos iniciais para seu controle, as chamadas de função do seu controle `DoPropExchange` `COleControl::DoPropExchange` . A versão de classe base troca as propriedades de ações do controle; você modifica a versão da classe derivada para as propriedades do Exchange que você adicionou ao seu controle.

`CPropExchange`pode ser usado para serializar as propriedades de um controle ou inicializar as propriedades de um controle após a carga ou a criação de um controle. As `ExchangeProp` `ExchangeFontProp` funções de membro e de `CPropExchange` são capazes de armazenar propriedades e carregá-las de diferentes mídias.

Para obter mais informações sobre como usar `CPropExchange` o, consulte o artigo [controles ActiveX do MFC: páginas de propriedades](../../mfc/mfc-activex-controls-property-pages.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CPropExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="cpropexchangeexchangeblobprop"></a><a name="exchangeblobprop"></a>CPropExchange::ExchangeBlobProp

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

As funções `CArchivePropExchange::ExchangeBlobProp` , `CResetPropExchange::ExchangeBlobProp` e `CPropsetPropExchange::ExchangeBlobProp` substituem essa função virtual pura.

## <a name="cpropexchangeexchangefontprop"></a><a name="exchangefontprop"></a>CPropExchange::ExchangeFontProp

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
Um ponteiro para a `IFontDisp` interface de uma fonte a ser usada para inicializar o estado padrão da propriedade Font.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Se a propriedade Font estiver sendo carregada da mídia para o controle, as características da fonte serão recuperadas do meio e o `CFontHolder` objeto referenciado pela *fonte* será inicializado com elas. Se a propriedade Font estiver sendo armazenada, as características no objeto Font serão gravadas na mídia.

As funções `CArchivePropExchange::ExchangeFontProp` , `CResetPropExchange::ExchangeFontProp` e `CPropsetPropExchange::ExchangeFontProp` substituem essa função virtual pura.

## <a name="cpropexchangeexchangepersistentprop"></a><a name="exchangepersistentprop"></a>CPropExchange::ExchangePersistentProp

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
Um ponteiro para uma variável que contém um ponteiro para a interface da propriedade `IUnknown` (essa variável normalmente é um membro de sua classe).

*IID*<br/>
ID da interface na propriedade que o controle usará.

*pUnkDefault*<br/>
Valor padrão da propriedade.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Se a propriedade estiver sendo carregada do arquivo para o controle, a propriedade será criada e inicializada a partir do arquivo. Se a propriedade estiver sendo armazenada, seu valor será gravado no arquivo.

As funções `CArchivePropExchange::ExchangePersistentProp` , `CResetPropExchange::ExchangePersistentProp` e `CPropsetPropExchange::ExchangePersistentProp` substituem essa função virtual pura.

## <a name="cpropexchangeexchangeprop"></a><a name="exchangeprop"></a>CPropExchange::ExchangeProp

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
|VT_I2|**`short`**|
|VT_I4|**`long`**|
|VT_BOOL|**BOOL**|
|VT_BSTR|`CString`|
|VT_CY|**CY**|
|VT_R4|**`float`**|
|VT_R8|**`double`**|

*pvProp*<br/>
Um ponteiro para o valor da propriedade.

*pvDefault*<br/>
Ponteiro para um valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o Exchange foi bem-sucedido; 0 se não for bem-sucedida.

### <a name="remarks"></a>Comentários

Se a propriedade estiver sendo carregada da mídia para o controle, o valor da propriedade será recuperado do meio e armazenado no objeto apontado por *pvProp*. Se a propriedade estiver sendo armazenada no meio, o valor do objeto apontado por *pvProp* será gravado na mídia.

As funções `CArchivePropExchange::ExchangeProp` , `CResetPropExchange::ExchangeProp` e `CPropsetPropExchange::ExchangeProp` substituem essa função virtual pura.

## <a name="cpropexchangeexchangeversion"></a><a name="exchangeversion"></a>CPropExchange::ExchangeVersion

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

## <a name="cpropexchangegetversion"></a><a name="getversion"></a>CPropExchange:: GetVersion

Chame essa função para recuperar o número de versão do controle.

```
DWORD GetVersion();
```

### <a name="return-value"></a>Valor retornado

O número de versão do controle.

## <a name="cpropexchangeisasynchronous"></a><a name="isasynchronous"></a>CPropExchange:: IsAsynchronous

Determina se as trocas de propriedades são feitas de forma assíncrona.

```
BOOL IsAsynchronous();
```

### <a name="return-value"></a>Valor retornado

Retornará TRUE se as propriedades forem trocadas de forma assíncrona, caso contrário, FALSE.

## <a name="cpropexchangeisloading"></a><a name="isloading"></a>CPropExchange:: isuploading

Chame essa função para determinar se as propriedades estão sendo carregadas no controle ou salvas dela.

```
BOOL IsLoading();
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se as propriedades estiverem sendo carregadas; caso contrário, 0.

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[COleControl::D oPropExchange](../../mfc/reference/colecontrol-class.md#dopropexchange)
