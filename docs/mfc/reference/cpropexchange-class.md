---
title: Classe CPropExchange | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPropExchange
dev_langs:
- C++
helpviewer_keywords:
- CPropExchange class
- OLE controls, persistence
- controls [MFC], OLE
ms.assetid: ed872180-e770-4942-892a-92139d501fab
caps.latest.revision: 22
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: 655d8e2f074c3bd12b1b52ece74efb844c7a9904
ms.lasthandoff: 02/25/2017

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
|[CPropExchange::ExchangeProp](#exchangeprop)|Propriedades de trocas de qualquer tipo interno.|  
|[CPropExchange::ExchangeVersion](#exchangeversion)|Troca o número de versão de um controle OLE.|  
|[CPropExchange::GetVersion](#getversion)|Recupera o número de versão de um controle OLE.|  
|[CPropExchange::IsAsynchronous](#isasynchronous)|Determina se as trocas de propriedade são feitas de forma assíncrona.|  
|[CPropExchange::IsLoading](#isloading)|Indica se as propriedades estão sendo carregado no controle ou salvos a partir dela.|  
  
## <a name="remarks"></a>Comentários  
 `CPropExchange`não tem uma classe base.  
  
 Estabelece o contexto e a direção de uma troca de propriedade.  
  
 Persistência é a troca de informações de estado do controle, geralmente representadas por suas propriedades, entre o controle em si e uma média.  
  
 A estrutura constrói um objeto derivado de `CPropExchange` quando ele é notificado que propriedades de um controle OLE devem ser carregados de ou procedimentos armazenados para persistente do armazenamento.  
  
 A estrutura transmite um ponteiro para esse `CPropExchange` objeto para o controle `DoPropExchange` função. Se você usou um Assistente para criar os arquivos iniciais para o seu controle, seu controle `DoPropExchange` chamadas de função `COleControl::DoPropExchange`. A versão da classe base troca propriedades de estoque do controle; Modificar versão da sua classe derivada para propriedades de exchange que você adicionou ao seu controle.  
  
 `CPropExchange`pode ser usado para serializar as propriedades de um controle ou inicializar as propriedades do controle após o carregamento ou a criação de um controle. O `ExchangeProp` e `ExchangeFontProp` funções de membro `CPropExchange` são capazes de armazenar propriedades e carregá-los de mídia diferentes.  
  
 Para obter mais informações sobre como usar o `CPropExchange`, consulte o artigo [controles ActiveX MFC: páginas de propriedade](../../mfc/mfc-activex-controls-property-pages.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CPropExchange`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxctl.h  
  
##  <a name="a-nameexchangeblobpropa--cpropexchangeexchangeblobprop"></a><a name="exchangeblobprop"></a>CPropExchange::ExchangeBlobProp  
 Serializa a uma propriedade que armazena dados de objeto binário grande (BLOB).  
  
```  
virtual BOOL ExchangeBlobProp(
    LPCTSTR pszPropName,  
    HGLOBAL* phBlob,  
    HGLOBAL hBlobDefault = NULL) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `phBlob`  
 Ponteiro para uma variável que aponta para onde a propriedade é armazenada (variável normalmente é um membro da sua classe).  
  
 `hBlobDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 O valor da propriedade é lido ou gravado a, conforme apropriado, a variável referenciada por `phBlob`. Se `hBlobDefault` for especificado, ele será usado como o valor da propriedade padrão. Esse valor é usado se, por algum motivo, a serialização do controle falhar.  
  
 As funções **CArchivePropExchange::ExchangeBlobProp**, **CResetPropExchange::ExchangeBlobProp**, e **CPropsetPropExchange::ExchangeBlobProp** substituem essa função virtual pura.  
  
##  <a name="a-nameexchangefontpropa--cpropexchangeexchangefontprop"></a><a name="exchangefontprop"></a>CPropExchange::ExchangeFontProp  
 Troca entre uma mídia de armazenamento e o controle de uma propriedade de fonte.  
  
```  
virtual BOOL ExchangeFontProp(
    LPCTSTR pszPropName,  
    CFontHolder& font,  
    const FONTDESC* pFontDesc,  
    LPFONTDISP pFontDispAmbient) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `font`  
 Uma referência a um [CFontHolder](../../mfc/reference/cfontholder-class.md) objeto que contém a propriedade font.  
  
 `pFontDesc`  
 Um ponteiro para um [FONTDESC](http://msdn.microsoft.com/library/windows/desktop/ms692782) estrutura que contém os valores para inicializar o estado padrão da propriedade fonte quando `pFontDispAmbient` é **nulo**.  
  
 `pFontDispAmbient`  
 Um ponteiro para o **IFontDisp** interface de uma fonte a ser usado para inicializar o estado padrão da propriedade font.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade font estiver sendo carregada a partir da mídia ao controle, características da fonte são recuperadas a partir da mídia e o `CFontHolder` objeto referenciado pelo `font` é inicializada com eles. Se a propriedade font está sendo armazenada, as características do objeto de fonte são gravadas na mídia.  
  
 As funções **CArchivePropExchange::ExchangeFontProp**, **CResetPropExchange::ExchangeFontProp**, e **CPropsetPropExchange::ExchangeFontProp** substituem essa função virtual pura.  
  
##  <a name="a-nameexchangepersistentpropa--cpropexchangeexchangepersistentprop"></a><a name="exchangepersistentprop"></a>CPropExchange::ExchangePersistentProp  
 Troca de uma propriedade entre o controle e um arquivo.  
  
```  
virtual BOOL ExchangePersistentProp(
    LPCTSTR pszPropName,  
    LPUNKNOWN* ppUnk,  
    REFIID iid,  
    LPUNKNOWN pUnkDefault) = 0;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `ppUnk`  
 Um ponteiro para uma variável que contém um ponteiro para a propriedade **IUnknown** interface (essa variável normalmente é um membro da sua classe).  
  
 `iid`  
 ID de interface da interface na propriedade que irá usar o controle.  
  
 `pUnkDefault`  
 Valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade está sendo carregada do arquivo para o controle, a propriedade é criada e inicializada a partir do arquivo. Se a propriedade está sendo armazenada, seu valor é gravado no arquivo.  
  
 As funções **CArchivePropExchange::ExchangePersistentProp**, **CResetPropExchange::ExchangePersistentProp**, e **CPropsetPropExchange::ExchangePersistentProp** substituem essa função virtual pura.  
  
##  <a name="a-nameexchangepropa--cpropexchangeexchangeprop"></a><a name="exchangeprop"></a>CPropExchange::ExchangeProp  
 Troca de uma propriedade entre uma mídia de armazenamento e o controle.  
  
```  
virtual BOOL ExchangeProp(
    LPCTSTR pszPropName,  
    VARTYPE vtProp,  
    void* pvProp,  
    const void* pvDefault = NULL) = 0 ;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pszPropName`  
 O nome da propriedade trocada.  
  
 `vtProp`  
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
  
 `pvProp`  
 Um ponteiro para o valor da propriedade.  
  
 *pvDefault*  
 Ponteiro para um valor padrão para a propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o exchange foi bem sucedido; 0 se não for bem-sucedida.  
  
### <a name="remarks"></a>Comentários  
 Se a propriedade estiver sendo carregada a partir da mídia para o controle, o valor da propriedade é recuperado a partir da mídia e armazenado no objeto apontado por `pvProp`. Se a propriedade estiver sendo armazenada na mídia, o valor do objeto apontado por `pvProp` é gravado na mídia.  
  
 As funções **CArchivePropExchange::ExchangeProp**, **CResetPropExchange::ExchangeProp**, e **CPropsetPropExchange::ExchangeProp** substituem essa função virtual pura.  
  
##  <a name="a-nameexchangeversiona--cpropexchangeexchangeversion"></a><a name="exchangeversion"></a>CPropExchange::ExchangeVersion  
 Chamado pela estrutura para lidar com a persistência de um número de versão.  
  
```  
virtual BOOL ExchangeVersion(
    DWORD& dwVersionLoaded,  
    DWORD dwVersionDefault,  
    BOOL bConvert);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwVersionLoaded*  
 Referência a uma variável onde será armazenado o número de versão dos dados persistentes que está sendo carregados.  
  
 `dwVersionDefault`  
 O número de versão atual do controle.  
  
 `bConvert`  
 Indica se deve converter os dados persistentes para a versão atual ou manter a mesma versão que foi carregada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a função for bem-sucedida; Caso contrário, 0.  
  
##  <a name="a-namegetversiona--cpropexchangegetversion"></a><a name="getversion"></a>CPropExchange::GetVersion  
 Chame essa função para recuperar o número de versão do controle.  
  
```  
DWORD GetVersion();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O número de versão do controle.  
  
##  <a name="a-nameisasynchronousa--cpropexchangeisasynchronous"></a><a name="isasynchronous"></a>CPropExchange::IsAsynchronous  
 Determina se as trocas de propriedade são feitas de forma assíncrona.  
  
```  
BOOL IsAsynchronous();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna TRUE se as propriedades são trocados de forma assíncrona, caso contrário, FALSE.  
  
##  <a name="a-nameisloadinga--cpropexchangeisloading"></a><a name="isloading"></a>CPropExchange::IsLoading  
 Chame essa função para determinar se as propriedades estão sendo carregados para o controle ou salvos dele.  
  
```  
BOOL IsLoading();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se propriedades estão sendo carregadas; Caso contrário, 0.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [COleControl::DoPropExchange](../../mfc/reference/colecontrol-class.md#dopropexchange)




