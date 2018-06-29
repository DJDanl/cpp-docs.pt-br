---
title: Classe CPropExchange | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fef6d3e30791d2a08a82d1b152cd849cd4ebf24b
ms.sourcegitcommit: be0e3457f2884551f18e183ef0ea65c3ded7f689
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/28/2018
ms.locfileid: "37078402"
---
# <a name="cpropexchange-class"></a>Classe CPropExchange
Oferece suporte à implementação de persistência para os controles OLE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE CPropExchange  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPropExchange::ExchangeBlobProp](#exchangeblobprop)|Troca de uma propriedade de objeto binário grande (BLOB).|  
|[CPropExchange::ExchangeFontProp](#exchangefontprop)|Troca de uma propriedade de fonte.|  
|[CPropExchange::ExchangePersistentProp](#exchangepersistentprop)|Troca de uma propriedade entre um controle e um arquivo.|  
|[CPropExchange::ExchangeProp](#exchangeprop)|Propriedades de qualquer tipo interno de troca.|  
|[CPropExchange::ExchangeVersion](#exchangeversion)|Troca o número de versão de um controle OLE.|  
|[CPropExchange::GetVersion](#getversion)|Recupera o número de versão de um controle OLE.|  
|[CPropExchange::IsAsynchronous](#isasynchronous)|Determina se as trocas de propriedade são executadas de modo assíncrono.|  
|[CPropExchange::IsLoading](#isloading)|Indica se as propriedades estão sendo carregado no controle ou salvo dele.|  
  
## <a name="remarks"></a>Comentários  
 `CPropExchange` não tem uma classe base.  
  
 Estabelece o contexto e a direção de um câmbio da propriedade.  
  
 Persistência é a troca de informações de estado do controle, geralmente representadas por suas propriedades, entre o controle em si e uma média.  
  
 A estrutura constrói um objeto derivado de `CPropExchange` quando ele é notificado que propriedades de um controle OLE devem ser carregados de ou armazenamento armazenado como persistente.  
  
 A estrutura transmite um ponteiro a este `CPropExchange` objeto para o controle `DoPropExchange` função. Se você usou um Assistente para criar os arquivos iniciais para o controle, seu controle `DoPropExchange` chamadas de função `COleControl::DoPropExchange`. A versão da classe base de troca de propriedades de estoque do controle; você modificar a versão do sua classe derivada exchange propriedades que você adicionou ao seu controle.  
  
 `CPropExchange` pode ser usado para serializar as propriedades de um controle ou inicializar propriedades de um controle em caso de carga ou criação de um controle. O `ExchangeProp` e `ExchangeFontProp` funções membro de `CPropExchange` são capazes de armazenar as propriedades para e carregá-los de mídia diferentes.  
  
 Para obter mais informações sobre como usar `CPropExchange`, consulte o artigo [controles ActiveX MFC: páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CPropExchange`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl. h  
  
##  <a name="exchangeblobprop"></a>  CPropExchange::ExchangeBlobProp  
 Serializa uma propriedade que armazena dados de objeto binário grande (BLOB).  
  
```  
virtual BOOL ExchangeBlobProp(
    LPCTSTR pszPropName,  
    HGLOBAL* phBlob,  
    HGLOBAL hBlobDefault = NULL) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszPropName*  
 O nome da propriedade que está sendo trocado.  
  
 *phBlob*  
 Ponteiro para uma variável que aponta para onde a propriedade é armazenada (variável normalmente é um membro da sua classe).  
  
 *hBlobDefault*  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado a, conforme apropriado, a variável referenciada por *phBlob*. Se *hBlobDefault* for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, a serialização do controle falhar.  
  
 As funções **CArchivePropExchange::ExchangeBlobProp**, **CResetPropExchange::ExchangeBlobProp**, e **CPropsetPropExchange::ExchangeBlobProp** substituir Essa função virtual pura.  
  
##  <a name="exchangefontprop"></a>  CPropExchange::ExchangeFontProp  
 Troca de uma propriedade de fonte entre uma mídia de armazenamento e o controle.  
  
```  
virtual BOOL ExchangeFontProp(
    LPCTSTR pszPropName,  
    CFontHolder& font,  
    const FONTDESC* pFontDesc,  
    LPFONTDISP pFontDispAmbient) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszPropName*  
 O nome da propriedade que está sendo trocado.  
  
 *Fonte*  
 Uma referência a um [CFontHolder](../../mfc/reference/cfontholder-class.md) objeto que contém a propriedade de fonte.  
  
 *pFontDesc*  
 Um ponteiro para um [FONTDESC](http://msdn.microsoft.com/library/windows/desktop/ms692782) estrutura que contém valores para inicializar o estado padrão da propriedade font quando *pFontDispAmbient* é **nulo**.  
  
 *pFontDispAmbient*  
 Um ponteiro para o **IFontDisp** interface de uma fonte a ser usado para inicializar o estado padrão da propriedade font.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade de fonte está sendo carregada da mídia para o controle, características da fonte são recuperadas do meio e o `CFontHolder` objeto referenciado por *fonte* é inicializada com eles. Se a propriedade font está sendo armazenada, as características do objeto de fonte são gravadas na mídia.  
  
 As funções **CArchivePropExchange::ExchangeFontProp**, **CResetPropExchange::ExchangeFontProp**, e **CPropsetPropExchange::ExchangeFontProp** substituir Essa função virtual pura.  
  
##  <a name="exchangepersistentprop"></a>  CPropExchange::ExchangePersistentProp  
 Troca de uma propriedade entre o controle e um arquivo.  
  
```  
virtual BOOL ExchangePersistentProp(
    LPCTSTR pszPropName,  
    LPUNKNOWN* ppUnk,  
    REFIID iid,  
    LPUNKNOWN pUnkDefault) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszPropName*  
 O nome da propriedade que está sendo trocado.  
  
 *ppUnk*  
 Um ponteiro para uma variável que contém um ponteiro para a propriedade **IUnknown** interface (essa variável normalmente é um membro da sua classe).  
  
 *IID*  
 ID de interface da interface na propriedade que irá usar o controle.  
  
 *pUnkDefault*  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade está sendo carregada do arquivo para o controle, a propriedade é criada e inicializada a partir do arquivo. Se a propriedade estiver sendo armazenada, seu valor é gravado no arquivo.  
  
 As funções **CArchivePropExchange::ExchangePersistentProp**, **CResetPropExchange::ExchangePersistentProp**, e **CPropsetPropExchange::ExchangePersistentProp** substituem essa função virtual pura.  
  
##  <a name="exchangeprop"></a>  CPropExchange::ExchangeProp  
 Troca de uma propriedade entre uma mídia de armazenamento e o controle.  
  
```  
virtual BOOL ExchangeProp(
    LPCTSTR pszPropName,  
    VARTYPE vtProp,  
    void* pvProp,  
    const void* pvDefault = NULL) = 0 ;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *pszPropName*  
 O nome da propriedade que está sendo trocado.  
  
 *vtProp*  
 Um símbolo que especifica o tipo da propriedade sendo trocado. Os possíveis valores são:  
  
|Símbolo|Tipo de propriedade|  
|------------|-------------------|  
|`VT_I2`|**short**|  
|`VT_I4`|**long**|  
|`VT_BOOL`|**BOOL**|  
|`VT_BSTR`|`CString`|  
|`VT_CY`|**CY**|  
|`VT_R4`|**float**|  
|`VT_R8`|**double**|  
  
 *pvProp*  
 Um ponteiro para o valor da propriedade.  
  
 *pvDefault*  
 Ponteiro para um valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem-sucedida; 0 se não houver êxito.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade está sendo carregada da mídia para o controle, o valor da propriedade é recuperado de médio porte e armazenado no objeto apontado pelo *pvProp*. Se a propriedade estiver sendo armazenada na mídia, o valor do objeto apontada pelo *pvProp* é gravado na mídia.  
  
 As funções **CArchivePropExchange::ExchangeProp**, **CResetPropExchange::ExchangeProp**, e **CPropsetPropExchange::ExchangeProp** substituição nesse pura função virtual.  
  
##  <a name="exchangeversion"></a>  CPropExchange::ExchangeVersion  
 Chamado pelo framework para lidar com a persistência de um número de versão.  
  
```  
virtual BOOL ExchangeVersion(
    DWORD& dwVersionLoaded,  
    DWORD dwVersionDefault,  
    BOOL bConvert);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwVersionLoaded*  
 Referência a uma variável onde o número de versão dos dados persistentes que está sendo carregados será armazenado.  
  
 *dwVersionDefault*  
 O número de versão atual do controle.  
  
 *bConvert*  
 Indica se deve converter os dados persistentes para a versão atual ou mantê-lo na mesma versão que foi carregada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função foi bem-sucedida. Caso contrário, 0.  
  
##  <a name="getversion"></a>  CPropExchange::GetVersion  
 Chame essa função para recuperar o número de versão do controle.  
  
```  
DWORD GetVersion();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de versão do controle.  
  
##  <a name="isasynchronous"></a>  CPropExchange::IsAsynchronous  
 Determina se as trocas de propriedade são executadas de modo assíncrono.  
  
```  
BOOL IsAsynchronous();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retornará TRUE se as propriedades são trocados de forma assíncrona, caso contrário, FALSE.  
  
##  <a name="isloading"></a>  CPropExchange::IsLoading  
 Chamar esta função para determinar se as propriedades estão sendo carregados para o controle ou salvos dele.  
  
```  
BOOL IsLoading();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se propriedades estão sendo carregadas; Caso contrário, 0.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [COleControl::DoPropExchange](../../mfc/reference/colecontrol-class.md#dopropexchange)



