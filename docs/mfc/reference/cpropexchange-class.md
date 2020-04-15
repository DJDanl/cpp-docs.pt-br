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
ms.openlocfilehash: 7818b15e502bb32640d6b9dbfe1a6e4927c70650
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363979"
---
# <a name="cpropexchange-class"></a>Classe CPropExchange

Apoia a implementação de persistência para seus controles OLE.

## <a name="syntax"></a>Sintaxe

```
class AFX_NOVTABLE CPropExchange
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CPropExchange::ExchangeBlobProp](#exchangeblobprop)|Troca uma propriedade binária de objeto grande (BLOB).|
|[CPropexchange::exchangefontprop](#exchangefontprop)|Troca uma propriedade de fonte.|
|[CPropexchange::Exchangepersistentprop](#exchangepersistentprop)|Troca uma propriedade entre um controle e um arquivo.|
|[CPropexchange::Exchangeprop](#exchangeprop)|Troca propriedades de qualquer tipo embutido.|
|[CPropExchange::ExchangeVersion](#exchangeversion)|Troca o número da versão de um controle OLE.|
|[CPropexchange::getversion](#getversion)|Recupera o número da versão de um controle OLE.|
|[CPropExchange::IsAsynchronous](#isasynchronous)|Determina se as trocas de propriedades são feitas de forma assíncrona.|
|[CPropexchange::isLoading](#isloading)|Indica se as propriedades estão sendo carregadas no controle ou salvas a partir dele.|

## <a name="remarks"></a>Comentários

`CPropExchange`não tem uma classe base.

Estabelece o contexto e a direção de uma troca de propriedades.

Persistência é a troca de informações estatais do controle, geralmente representadas por suas propriedades, entre o próprio controle e um meio.

A estrutura constrói um objeto `CPropExchange` derivado de quando é notificado de que as propriedades de um controle OLE devem ser carregadas ou armazenadas para armazenamento persistente.

A estrutura passa um `CPropExchange` ponteiro para este `DoPropExchange` objeto para a função do seu controle. Se você usou um assistente para criar os arquivos `DoPropExchange` iniciais `COleControl::DoPropExchange`para o seu controle, a função do controle chama . A versão de classe base troca as propriedades de ações do controle; você modifica a versão da sua classe derivada para trocar propriedades que você adicionou ao seu controle.

`CPropExchange`pode ser usado para serializar as propriedades de um controle ou inicializar as propriedades de um controle na carga ou criação de um controle. As `ExchangeProp` `ExchangeFontProp` funções e `CPropExchange` membros são capazes de armazenar propriedades e carregá-las de diferentes mídias.

Para obter mais `CPropExchange`informações sobre o uso, consulte o artigo [MFC ActiveX Controls: Property Pages](../../mfc/mfc-activex-controls-property-pages.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CPropExchange`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="cpropexchangeexchangeblobprop"></a><a name="exchangeblobprop"></a>CPropExchange::ExchangeBlobProp

Serializa uma propriedade que armazena dados binários de objetogrande (BLOB).

```
virtual BOOL ExchangeBlobProp(
    LPCTSTR pszPropName,
    HGLOBAL* phBlob,
    HGLOBAL hBlobDefault = NULL) = 0;
```

### <a name="parameters"></a>Parâmetros

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*phBlob*<br/>
Ponteiro para uma variável apontando para onde a propriedade é armazenada (variável é tipicamente um membro de sua classe).

*Hblobdefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

O valor da propriedade é lido ou escrito para, conforme apropriado, a variável referenciada por *phBlob*. Se *hBlobDefault* for especificado, ele será usado como o valor padrão da propriedade. Esse valor é usado se, por qualquer razão, a serialização do controle falhar.

As `CArchivePropExchange::ExchangeBlobProp`funções `CResetPropExchange::ExchangeBlobProp`, `CPropsetPropExchange::ExchangeBlobProp` e anular esta função virtual pura.

## <a name="cpropexchangeexchangefontprop"></a><a name="exchangefontprop"></a>CPropexchange::exchangefontprop

Troca uma propriedade de fonte entre um meio de armazenamento e o controle.

```
virtual BOOL ExchangeFontProp(
    LPCTSTR pszPropName,
    CFontHolder& font,
    const FONTDESC* pFontDesc,
    LPFONTDISP pFontDispAmbient) = 0;
```

### <a name="parameters"></a>Parâmetros

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Fonte*<br/>
Uma referência a um objeto [CFontHolder](../../mfc/reference/cfontholder-class.md) que contém a propriedade fonte.

*pFontDesc*<br/>
Um ponteiro para uma estrutura [FONTDESC](/windows/win32/api/olectl/ns-olectl-fontdesc) contendo valores para inicializar o estado padrão da propriedade da fonte quando *pFontDispAmbient* é NULL.

*Pfontdispambient*<br/>
Um ponteiro `IFontDisp` para a interface de uma fonte a ser usada para inicializar o estado padrão da propriedade da fonte.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

Se a propriedade da fonte estiver sendo carregada do meio para o controle, as `CFontHolder` características da fonte serão recuperadas do meio e o objeto referenciado por *fonte* será inicializado com eles. Se a propriedade da fonte estiver sendo armazenada, as características do objeto da fonte serão escritas para o meio.

As `CArchivePropExchange::ExchangeFontProp`funções `CResetPropExchange::ExchangeFontProp`, `CPropsetPropExchange::ExchangeFontProp` e anular esta função virtual pura.

## <a name="cpropexchangeexchangepersistentprop"></a><a name="exchangepersistentprop"></a>CPropexchange::Exchangepersistentprop

Troca uma propriedade entre o controle e um arquivo.

```
virtual BOOL ExchangePersistentProp(
    LPCTSTR pszPropName,
    LPUNKNOWN* ppUnk,
    REFIID iid,
    LPUNKNOWN pUnkDefault) = 0;
```

### <a name="parameters"></a>Parâmetros

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*ppUnk*<br/>
Um ponteiro para uma variável contendo um `IUnknown` ponteiro para a interface da propriedade (esta variável é tipicamente um membro da sua classe).

*Iid*<br/>
Interface ID da interface na propriedade que o controle usará.

*pUnkDefault*<br/>
Valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

Se a propriedade estiver sendo carregada do arquivo para o controle, a propriedade será criada e inicializada a partir do arquivo. Se a propriedade estiver sendo armazenada, seu valor será gravado no arquivo.

As `CArchivePropExchange::ExchangePersistentProp`funções `CResetPropExchange::ExchangePersistentProp`, `CPropsetPropExchange::ExchangePersistentProp` e anular esta função virtual pura.

## <a name="cpropexchangeexchangeprop"></a><a name="exchangeprop"></a>CPropexchange::Exchangeprop

Troca uma propriedade entre um meio de armazenamento e o controle.

```
virtual BOOL ExchangeProp(
    LPCTSTR pszPropName,
    VARTYPE vtProp,
    void* pvProp,
    const void* pvDefault = NULL) = 0 ;
```

### <a name="parameters"></a>Parâmetros

*Pszpropname*<br/>
O nome da propriedade que está sendo trocada.

*Vtprop*<br/>
Um símbolo especificando o tipo da propriedade que está sendo trocada. Os valores possíveis são:

|Símbolo|Tipo de propriedade|
|------------|-------------------|
|VT_I2|**Curto**|
|VT_I4|**Longas**|
|VT_BOOL|**Bool**|
|VT_BSTR|`CString`|
|VT_CY|**CY**|
|VT_R4|**float**|
|VT_R8|**double**|

*Pvprop*<br/>
Um ponteiro para o valor da propriedade.

*pvDefault*<br/>
Ponteiro para um valor padrão para a propriedade.

### <a name="return-value"></a>Valor retornado

Não zero se a troca foi bem sucedida; 0 se não tiver sucesso.

### <a name="remarks"></a>Comentários

Se a propriedade estiver sendo carregada do meio para o controle, o valor da propriedade é recuperado do meio e armazenado no objeto apontado pelo *pvProp*. Se a propriedade estiver sendo armazenada para o meio, o valor do objeto apontado por *pvProp* é escrito para o meio.

As `CArchivePropExchange::ExchangeProp`funções `CResetPropExchange::ExchangeProp`, `CPropsetPropExchange::ExchangeProp` e anular esta função virtual pura.

## <a name="cpropexchangeexchangeversion"></a><a name="exchangeversion"></a>CPropExchange::ExchangeVersion

Chamado pela estrutura para lidar com a persistência de um número de versão.

```
virtual BOOL ExchangeVersion(
    DWORD& dwVersionLoaded,
    DWORD dwVersionDefault,
    BOOL bConvert);
```

### <a name="parameters"></a>Parâmetros

*dwVersionLoaded*<br/>
Consulte uma variável onde o número de versão dos dados persistentes que estão sendo carregados será armazenado.

*dwVersionDefault*<br/>
O número da versão atual do controle.

*bConverter*<br/>
Indica se deve converter dados persistentes para a versão atual ou mantê-los na mesma versão que foi carregada.

### <a name="return-value"></a>Valor retornado

Não zero se a função foi bem sucedida; 0 caso contrário.

## <a name="cpropexchangegetversion"></a><a name="getversion"></a>CPropexchange::getversion

Ligue para esta função para recuperar o número da versão do controle.

```
DWORD GetVersion();
```

### <a name="return-value"></a>Valor retornado

O número da versão do controle.

## <a name="cpropexchangeisasynchronous"></a><a name="isasynchronous"></a>CPropExchange::IsAsynchronous

Determina se as trocas de propriedades são feitas de forma assíncrona.

```
BOOL IsAsynchronous();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se as propriedades forem trocadas de forma assíncrona, caso contrário, FALSA.

## <a name="cpropexchangeisloading"></a><a name="isloading"></a>CPropexchange::isLoading

Ligue para esta função para determinar se as propriedades estão sendo carregadas para o controle ou salvas dela.

```
BOOL IsLoading();
```

### <a name="return-value"></a>Valor retornado

Não zero se as propriedades estiverem sendo carregadas; caso contrário, 0.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[COleControl::DoPropExchange](../../mfc/reference/colecontrol-class.md#dopropexchange)
