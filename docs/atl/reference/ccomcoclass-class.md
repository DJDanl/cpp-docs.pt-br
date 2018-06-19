---
title: Classe de CComCoClass | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComCoClass
- ATLCOM/ATL::CComCoClass
- ATLCOM/ATL::CComCoClass::CreateInstance
- ATLCOM/ATL::CComCoClass::Error
- ATLCOM/ATL::CComCoClass::GetObjectCLSID
- ATLCOM/ATL::CComCoClass::GetObjectDescription
dev_langs:
- C++
helpviewer_keywords:
- CComCoClass class
- aggregation [C++], aggregation models
ms.assetid: 67cfefa4-8df9-47fa-ad58-2d1a1ae25762
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 738d7e937acf2d3299be97b4f091c698582911d5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32365456"
---
# <a name="ccomcoclass-class"></a>Classe de CComCoClass
Essa classe fornece métodos para criar instâncias de uma classe e obter suas propriedades.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, const CLSID* pclsid = &CLSID_NULL>  
class CComCoClass
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `CComCoClass`.  
  
 *pclsid*  
 Um ponteiro para o CLSID do objeto.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCoClass::CreateInstance](#createinstance)|(Estático) Cria uma instância da classe e consultas para uma interface.|  
|[CComCoClass::Error](#error)|(Estático) Retorna as informações de erros para o cliente.|  
|[CComCoClass::GetObjectCLSID](#getobjectclsid)|(Estático) Retorna o identificador de classe do objeto.|  
|[CComCoClass::GetObjectDescription](#getobjectdescription)|(Estático) Substituição para retornar a descrição do objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CComCoClass` fornece métodos para recuperar o CLSID de um objeto, as informações de erro de configuração e criar instâncias da classe. Nenhuma classe registrada no [mapa de objeto](http://msdn.microsoft.com/en-us/b57619cc-534f-4b8f-bfd4-0c12f937202f) deve ser derivado de `CComCoClass`.  
  
 `CComCoClass` também define o modelo padrão de fábrica e agregação de classe para seu objeto. `CComCoClass` usa as seguintes duas macros:  
  
- [DECLARE_CLASSFACTORY](aggregation-and-class-factory-macros.md#declare_classfactory) declara a fábrica de classe para ser [CComClassFactory](../../atl/reference/ccomclassfactory-class.md).  
  
- [DECLARE_AGGREGATABLE](aggregation-and-class-factory-macros.md#declare_aggregatable) declara que o objeto pode ser agregado.  
  
 Você pode substituir qualquer um desses padrões especificando outra macro em sua definição de classe. Por exemplo, para usar [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) em vez de `CComClassFactory`, especifique o [DECLARE_CLASSFACTORY2](aggregation-and-class-factory-macros.md#declare_classfactory2) macro:  
  
 [!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/ccomcoclass-class_1.h)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
  
##  <a name="createinstance"></a>  CComCoClass::CreateInstance  
 Use essas `CreateInstance` funções para criar uma instância de uma COM object e recuperar um ponteiro de interface sem usar a API de COM.  
  
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
 [in] Externo desconhecido ou controlar desconhecido da agregação.  
  
 `pp`  
 [out] O endereço de uma variável de ponteiro que recebe o ponteiro de interface solicitada se a criação for bem-sucedida.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor. Consulte [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615) no SDK do Windows para obter uma descrição dos valores de retorno possíveis.  
  
### <a name="remarks"></a>Comentários  
 Use a primeira sobrecarga dessa função para a criação de objeto típico; Use a segunda sobrecarga quando você precisa agregar o objeto que está sendo criado.  
  
 A classe ATL que implementa o objeto COM necessário (ou seja, a classe usada como o primeiro parâmetro de modelo para [CComCoClass](../../atl/reference/ccomcoclass-class.md)) deve estar no mesmo projeto como o código de chamada. A criação do objeto COM é realizada pela fábrica de classe registrada para essa classe ATL.  
  
 Essas funções são úteis para a criação de objetos que você ter impedido de ser instanciável externamente usando o [OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO](object-map-macros.md#object_entry_non_createable_ex_auto) macro. Eles também são úteis em situações em que você deseja evitar a API de COM para fins de eficiência.  
  
 Observe que a interface `Q` deve ter um IID associado a ele que pode ser recuperado usando o [uuidof](../../cpp/uuidof-operator.md) operador.  
  
### <a name="example"></a>Exemplo  
 No exemplo a seguir, `CDocument` é gerado pelo assistente ATL classe derivada de `CComCoClass` que implementa o **IDocument** interface. A classe é registrada no mapa do objeto com o `OBJECT_ENTRY_NON_CREATEABLE_EX_AUTO` para que os clientes não é possível criar instâncias de documento usando [CoCreateInstance](http://msdn.microsoft.com/library/windows/desktop/ms686615). `CApplication` é uma CoClass que fornece um método em uma de suas próprias interfaces COM para criar instâncias da classe do documento. O código a seguir mostra como é fácil criar instâncias da classe de documento usando o `CreateInstance` membro herdado da `CComCoClass` classe base.  
  
 [!code-cpp[NVC_ATL_COM#11](../../atl/codesnippet/cpp/ccomcoclass-class_2.cpp)]  
  
##  <a name="error"></a>  CComCoClass::Error  
 Essa função estática configura o `IErrorInfo` interface para fornecer informações de erro para o cliente.  
  
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
 [in] O identificador de recurso em que a cadeia de caracteres de descrição de erro é armazenada. Esse valor deve estar entre 0x0200 e 0xFFFF, inclusive. Em compilações de depuração, uma **ASSERT** ocorrerá se `nID` não indexa uma cadeia de caracteres válida. Em compilações de versão, a cadeia de caracteres de descrição de erro será definida como "Erro desconhecido".  
  
 `dwHelpID`  
 [in] O identificador de contexto de ajuda para o erro.  
  
 `lpszHelpFile`  
 [in] O caminho e o nome do arquivo de Ajuda que descreve o erro.  
  
 `hInst`  
 [in] O identificador para o recurso. Por padrão, esse parâmetro é **_AtlModule::GetResourceInstance**, onde **_AtlModule** é a instância global do [CAtlModule](../../atl/reference/catlmodule-class.md).  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor. Para obter detalhes, consulte Observações.  
  
### <a name="remarks"></a>Comentários  
 Para chamar `Error`, o objeto deve implementar a `ISupportErrorInfo Interface` interface.  
  
 Se o `hRes` parâmetro é diferente de zero, em seguida, `Error` retorna o valor de `hRes`. Se `hRes` for zero, então as primeiras quatro versões do `Error` retornar `DISP_E_EXCEPTION`. As duas últimas versões retornam o resultado da macro **MAKE_HRESULT (1, FACILITY_ITF,** `nID` **)**.  
  
##  <a name="getobjectclsid"></a>  CComCoClass::GetObjectCLSID  
 Fornece uma maneira consistente de recuperar o CLSID do objeto.  
  
```
static const CLSID& WINAPI GetObjectCLSID();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Identificador de classe do objeto.  
  
##  <a name="getobjectdescription"></a>  CComCoClass::GetObjectDescription  
 Função estática recupera a descrição de texto para seu objeto de classe.  
  
```
static LPCTSTR WINAPI GetObjectDescription();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Descrição do objeto de classe.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão retorna **nulo**. Você pode substituir esse método com o [DECLARE_OBJECT_DESCRIPTION](object-map-macros.md#declare_object_description) macro. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#12](../../atl/codesnippet/cpp/ccomcoclass-class_3.h)]  
  
 `GetObjectDescription` é chamado pelo **IComponentRegistrar::GetComponents**. **IComponentRegistrar** é uma interface de automação que permite registrar e cancelar o registro de componentes individuais em uma DLL. Quando você cria um objeto do registrador de componente com o Assistente de projeto de ATL, o assistente automaticamente implementará o **IComponentRegistrar** interface. **IComponentRegistrar** normalmente é usado pelo Microsoft Transaction Server.  
  
 Para obter mais informações sobre o Assistente de projeto de ATL, consulte o artigo [criando um projeto de ATL](../../atl/reference/creating-an-atl-project.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
