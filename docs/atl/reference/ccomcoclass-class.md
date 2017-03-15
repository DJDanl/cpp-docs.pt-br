---
title: Classe CComCoClass | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComCoClass
- ATL.CComCoClass
- ATL::CComCoClass
dev_langs:
- C++
helpviewer_keywords:
- CComCoClass class
- aggregation [C++], aggregation models
ms.assetid: 67cfefa4-8df9-47fa-ad58-2d1a1ae25762
caps.latest.revision: 19
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
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 6201051a38ac65788086dcf7ee4c3f3441988e71
ms.lasthandoff: 02/25/2017

---
# <a name="ccomcoclass-class"></a>Classe CComCoClass
Essa classe fornece métodos para criar instâncias de uma classe e obter suas propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, const CLSID* pclsid = &CLSID_NULL>  
class CComCoClass
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `CComCoClass`.  
  
 *pclsid*  
 Um ponteiro para o CLSID do objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCoClass::CreateInstance](#createinstance)|(Estático) Cria uma instância da classe e consultas de uma interface.|  
|[CComCoClass::Error](#error)|(Estático) Retorna informações de erros para o cliente.|  
|[CComCoClass::GetObjectCLSID](#getobjectclsid)|(Estático) Retorna o identificador de classe do objeto.|  
|[CComCoClass::GetObjectDescription](#getobjectdescription)|(Estático) Substituição para retornar a descrição do objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComCoClass`fornece métodos para recuperar o CLSID de um objeto, definindo as informações de erro e criar instâncias da classe. Qualquer classe registrada no [mapa objetos](http://msdn.microsoft.com/en-us/b57619cc-534f-4b8f-bfd4-0c12f937202f) deve ser derivado de `CComCoClass`.  
  
 `CComCoClass`também define o modelo padrão de fábrica e agregação de classe para o objeto. `CComCoClass`usa as duas macros a seguir:  
  
- [DECLARE_CLASSFACTORY](http://msdn.microsoft.com/library/51a6b925-07c0-4d3a-9174-0b8c808975e4) declara a fábrica de classes para ser [CComClassFactory](../../atl/reference/ccomclassfactory-class.md).  
  
- [DECLARE_AGGREGATABLE](http://msdn.microsoft.com/library/e7e568d7-04e0-4226-b5dc-224deed229ab) declara que o objeto pode ser agregado.  
  
 Você pode substituir qualquer um desses padrões especificando outra macro na definição de classe. Por exemplo, para usar [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) em vez de `CComClassFactory`, especifique o [DECLARE_CLASSFACTORY2](http://msdn.microsoft.com/library/38a6c969-7297-4bb1-9ba6-1fe2d355b285) macro:  
  
 [!code-cpp[NVC_ATL_COM N º&2;](../../atl/codesnippet/cpp/ccomcoclass-class_1.h)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="a-namecreateinstancea--ccomcoclasscreateinstance"></a><a name="createinstance"></a>CComCoClass::CreateInstance  
 Use estas `CreateInstance` funções para criar uma instância de uma COM object e recuperar um ponteiro de interface sem usar a API COM.  
  
```
template <class  Q>
static HRESULT CreateInstance( Q** pp);

template <class  Q>
static HRESULT CreateInstance(IUnknown* punkOuter, Q** pp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `Q`  
 A interface COM que deve ser retornada por meio de `pp`.  
  
 *punkOuter*  
 [in] O externo desconhecido ou controlar desconhecido da agregação.  
  
 `pp`  
 [out] O endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitada se a criação for bem-sucedida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor. Consulte [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma descrição dos possíveis valores de retorno.  
  
### <a name="remarks"></a>Comentários  
 Use a primeira sobrecarga dessa função de criação de objeto típico. Use a segunda sobrecarga quando você precisa agregar o objeto que está sendo criado.  
  
 A classe do ATL que implementa o objeto COM necessário (ou seja, a classe usada como o primeiro parâmetro de modelo para [CComCoClass](../../atl/reference/ccomcoclass-class.md)) deve estar no mesmo projeto como o código de chamada. A criação do objeto COM é realizada pela fábrica de classe registrada para essa classe ATL.  
  
 Essas funções são úteis para a criação de objetos que você tenha impedido de ser criáveis externamente usando o [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](http://msdn.microsoft.com/library/abdc093c-6502-42de-8419-b7ebf45299d1) macro. Eles também são úteis em situações em que você deseja evitar a API COM para fins de eficiência.  
  
 Observe que a interface `Q` deve ter uma IID associada a ele que pode ser recuperada usando o [uuidof](../../cpp/uuidof-operator.md) operador.  
  
### <a name="example"></a>Exemplo  
 No exemplo a seguir, `CDocument` é gerado pelo assistente ATL classe derivada de `CComCoClass` que implementa o **IDocument** interface. A classe é registrada no mapa de objetos com o `OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO` para que os clientes não é possível criar instâncias do documento usando [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615). `CApplication`é uma CoClass que fornece um método em uma de suas próprias interfaces COM para criar instâncias da classe do documento. O código a seguir mostra como é fácil criar instâncias da classe de documento usando o `CreateInstance` membro herdado da `CComCoClass` classe base.  
  
 [!code-cpp[NVC_ATL_COM N º&11;](../../atl/codesnippet/cpp/ccomcoclass-class_2.cpp)]  
  
##  <a name="a-nameerrora--ccomcoclasserror"></a><a name="error"></a>CComCoClass::Error  
 A função estática configura o `IErrorInfo` interface para fornecer informações de erro para o cliente.  
  
```
static HRESULT WINAPI Error(
    LPCOLESTR lpszDesc,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    LPCOLESTR lpszDesc,
    DWORD dwHelpID,
    LPCOLESTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    LPCSTR lpszDesc,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    LPCSTR lpszDesc,
    DWORD dwHelpID,
    LPCSTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0);

static HRESULT WINAPI Error(
    UINT nID,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0,
    HINSTANCE hInst = _AtlBaseModule.GetResourceInstance ());

static HRESULT Error(
    UINT nID,
    DWORD dwHelpID,
    LPCOLESTR lpszHelpFile,
    const IID& iid = GUID_NULL,
    HRESULT hRes = 0,
    HINSTANCE hInst = _AtlBaseModule.GetResourceInstance());
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszDesc`  
 [in] A cadeia de caracteres que descreve o erro. A versão Unicode de `Error` Especifica que `lpszDesc` é do tipo **LPCOLESTR**; a versão ANSI Especifica um tipo de `LPCSTR`.  
  
 `iid`  
 [in] O IID da interface definindo o erro ou `GUID_NULL` (o valor padrão) se o erro é definido pelo sistema operacional.  
  
 `hRes`  
 [in] O `HRESULT` serem retornadas ao chamador. O valor padrão é 0. Para obter mais detalhes sobre `hRes`, consulte comentários.  
  
 `nID`  
 [in] O identificador de recurso onde a cadeia de caracteres de descrição do erro está armazenada. Esse valor deve estar entre 0x0200 e 0xFFFF, inclusive. Em compilações de depuração, uma **ASSERT** resultará se `nID` não indexar uma sequência válida. Em compilações de versão, a cadeia de caracteres de descrição de erro será definida como "Erro desconhecido".  
  
 `dwHelpID`  
 [in] O identificador de contexto de ajuda para o erro.  
  
 `lpszHelpFile`  
 [in] O caminho e o nome do arquivo de Ajuda que descreve o erro.  
  
 `hInst`  
 [in] O identificador para o recurso. Por padrão, esse parâmetro é **_AtlModule::GetResourceInstance**, onde **_AtlModule** é a instância global do [CAtlModule](../../atl/reference/catlmodule-class.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor. Para obter detalhes, consulte Observações.  
  
### <a name="remarks"></a>Comentários  
 Para chamar `Error`, seu objeto deve implementar o `ISupportErrorInfo Interface` interface.  
  
 Se o `hRes` parâmetro é diferente de zero, então `Error` retorna o valor de `hRes`. Se `hRes` for zero, então as quatro primeiras versões do `Error` retornar `DISP_E_EXCEPTION`. As duas últimas versões retornam o resultado da macro **MAKE_HRESULT (1, FACILITY_ITF,** `nID` **)**.  
  
##  <a name="a-namegetobjectclsida--ccomcoclassgetobjectclsid"></a><a name="getobjectclsid"></a>CComCoClass::GetObjectCLSID  
 Fornece uma maneira consistente de recuperar o CLSID do objeto.  
  
```
static const CLSID& WINAPI GetObjectCLSID();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador de classe do objeto.  
  
##  <a name="a-namegetobjectdescriptiona--ccomcoclassgetobjectdescription"></a><a name="getobjectdescription"></a>CComCoClass::GetObjectDescription  
 A função estática recupera a descrição de texto para o objeto de classe.  
  
```
static LPCTSTR WINAPI GetObjectDescription();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Descrição do objeto de classe.  
  
### <a name="remarks"></a>Comentários  
 Retorna a implementação padrão **nulo**. Você pode substituir esse método com o [DECLARE_OBJECT_DESCRIPTION](http://msdn.microsoft.com/library/32ac881c-97b1-44e2-a017-0e23eb99ac93) macro. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM&#12;](../../atl/codesnippet/cpp/ccomcoclass-class_3.h)]  
  
 `GetObjectDescription`chamado por **IComponentRegistrar::GetComponents**. **IComponentRegistrar** é uma interface de automação que permite registrar e cancelar o registro de componentes individuais em uma DLL. Quando você cria um objeto de componente registrador com ATL Project Wizard, o assistente automaticamente implementará o **IComponentRegistrar** interface. **IComponentRegistrar** normalmente é usado pelo Microsoft Transaction Server.  
  
 Para obter mais informações sobre os ATL Project Wizard, consulte o artigo [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)

