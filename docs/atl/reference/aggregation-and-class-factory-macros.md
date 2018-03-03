---
title: "Macros de fábrica de classe e agregação | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- atlcom/ATL::DECLARE_AGGREGATABLE
- atlcom/ATL::DECLARE_CLASSFACTORY
- atlcom/ATL::DECLARE_CLASSFACTORY_EX
- atlcom/ATL::DECLARE_CLASSFACTORY_AUTO_THREAD
- atlcom/ATL::DECLARE_CLASSFACTORY_SINGLETON
- atlcom/ATL::DECLARE_GET_CONTROLLING_UNKNOWN
- atlcom/ATL::DECLARE_NOT_AGGREGATABLE
- atlcom/ATL::DECLARE_ONLY_AGGREGATABLE
- atlcom/ATL::DECLARE_POLY_AGGREGATABLE
- atlcom/ATL::DECLARE_PROTECT_FINAL_CONSTRUCT
- atlcom/ATL::DECLARE_VIEW_STATUS
dev_langs:
- C++
helpviewer_keywords:
- class factories, ATL macros
- aggregation [C++], ATL macros
ms.assetid: d99d379a-0eec-481f-8daa-252dac18f163
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8d18afdfe08a97a7a685b373b1f8951799836ab1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="aggregation-and-class-factory-macros"></a>Macros de fábrica de classe e de agregação
Essas macros fornecem maneiras de controlar a agregação e da declaração de fábricas de classe.  
  
|||  
|-|-|  
|[DECLARE_AGGREGATABLE](#declare_aggregatable)|Declara que o objeto pode ser agregado (o padrão).|  
|[DECLARE_CLASSFACTORY](#declare_classfactory)|Declara a fábrica de classe para ser [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), a fábrica de classes ATL padrão.|  
|[DECLARE_CLASSFACTORY_EX](#declare_classfactory_ex)|Declara o objeto de fábrica de classe para a classe de fábrica.|  
|[DECLARE_CLASSFACTORY2](#declare_classfactory2)|Declara [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) para a classe de fábrica.|  
|[DECLARE_CLASSFACTORY_AUTO_THREAD](#declare_classfactory_auto_thread)|Declara [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) para a classe de fábrica.|  
|[DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton)|Declara [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md) para a classe de fábrica.|  
|[DECLARE_GET_CONTROLLING_UNKNOWN](#declare_get_controlling_unknown)|Declara uma máquina virtual `GetControllingUnknown` função.|  
|[DECLARE_NOT_AGGREGATABLE](#declare_not_aggregatable)|Declara que o objeto não pode ser agregado.|  
|[DECLARE_ONLY_AGGREGATABLE](#declare_only_aggregatable)|Declara que o objeto deve ser agregado.|  
|[DECLARE_POLY_AGGREGATABLE](#declare_poly_aggregatable)|Verifica o valor do desconhecido externo e declara seu objeto agregável ou não agregável, conforme apropriado.|  
|[DECLARE_PROTECT_FINAL_CONSTRUCT](#declare_protect_final_construct)|Protege o objeto externo de exclusão durante a construção de um objeto interno.|  
|[DECLARE_VIEW_STATUS](#declare_view_status)|Especifica o **VIEWSTATUS** sinalizadores para o contêiner.|  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlcom.h  
   
##  <a name="declare_aggregatable"></a>DECLARE_AGGREGATABLE  
 Especifica se o objeto pode ser agregado.  
  
```
DECLARE_AGGREGATABLE( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome da classe que você está definindo como agregável.  
  
### <a name="remarks"></a>Comentários  
 [CComCoClass](../../atl/reference/ccomcoclass-class.md) contém esta macro para especificar o modelo de agregação padrão. Para substituir esse padrão, especifique o [DECLARE_NOT_AGGREGATABLE](#declare_not_aggregatable) ou [DECLARE_ONLY_AGGREGATABLE](#declare_only_aggregatable) macro em sua definição de classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#121](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_1.h)]  
  
##  <a name="declare_classfactory"></a>DECLARE_CLASSFACTORY  
 Declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) para a classe de fábrica.  
  
```
DECLARE_CLASSFACTORY()
```  
  
### <a name="remarks"></a>Comentários  
 [CComCoClass](../../atl/reference/ccomcoclass-class.md) usa esta macro para declarar a fábrica de classe padrão para o objeto.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#55](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_2.h)]  
  
##  <a name="ccomclassfactory_class"></a>Classe CComClassFactory  
 Essa classe implementa o [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) interface.  
  
```
class CComClassFactory : public IClassFactory,
public CComObjectRootEx<CComGlobalsThreadModel>
```  
  
### <a name="remarks"></a>Comentários  
 `CComClassFactory`implementa o [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) interface, que contém métodos para criação de um objeto de um determinado CLSID, bem como bloqueio a fábrica de classes na memória para permitir que novos objetos a ser criada mais rapidamente. **IClassFactory** deve ser implementado para cada classe que você registre-se no registro do sistema e que você atribuir um CLSID.  
  
 Objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara `CComClassFactory` como a fábrica de classe padrão. Para substituir esse padrão, especifique uma da `DECLARE_CLASSFACTORY` *XXX* macros em sua definição de classe. Por exemplo, o [DECLARE_CLASSFACTORY_EX](#declare_classfactory_ex) macro usa a classe especificada para a fábrica de classe:  
  
 [!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_3.h)]  
  
 A definição de classe acima Especifica que **CMyClassFactory** será usado como a fábrica de classes do objeto padrão. **CMyClassFactory** deve derivar de `CComClassFactory` e substituir `CreateInstance`.  
  
 ATL fornece três outras macros que declare uma fábrica de classe:  
  
- [DECLARE_CLASSFACTORY2](#declare_classfactory2) usa [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md), que controla a criação por meio de uma licença.  
  
- [DECLARE_CLASSFACTORY_AUTO_THREAD](#declare_classfactory_auto_thread) usa [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md), que cria os objetos em vários apartments.  
  
- [DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton) usa [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md), que constrói uma única [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) objeto.  
  
##  <a name="declare_classfactory_ex"></a>DECLARE_CLASSFACTORY_EX  
 Declara `cf` para a classe de fábrica.  
  
```
DECLARE_CLASSFACTORY_EX( cf )
```  
  
### <a name="parameters"></a>Parâmetros  
 `cf`  
 [in] O nome da classe que implementa o objeto de fábrica de classe.  
  
### <a name="remarks"></a>Comentários  
 O `cf` parâmetro deve ser derivado de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e substituir o `CreateInstance` método.  
  
 [CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui o [DECLARE_CLASSFACTORY](#declare_classfactory) macro, que especifica `CComClassFactory` como a fábrica de classe padrão. No entanto, ao incluir o `DECLARE_CLASSFACTORY_EX` macro na definição de classe do objeto, você pode substituir esse padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#8](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_3.h)]  
  
##  <a name="declare_classfactory2"></a>DECLARE_CLASSFACTORY2  
 Declara [CComClassFactory2](../../atl/reference/ccomclassfactory2-class.md) para a classe de fábrica.  
  
```
DECLARE_CLASSFACTORY2( lic )
```  
  
### <a name="parameters"></a>Parâmetros  
 *lic.*  
 [in] Uma classe que implementa `VerifyLicenseKey`, `GetLicenseKey`, e `IsLicenseValid`.  
  
### <a name="remarks"></a>Comentários  
 [CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui o [DECLARE_CLASSFACTORY](#declare_classfactory) macro, que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. No entanto, ao incluir o `DECLARE_CLASSFACTORY2` macro na definição de classe do objeto, você pode substituir esse padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_4.h)]  
  
##  <a name="ccomclassfactory2_class"></a>Classe CComClassFactory2  
 Essa classe implementa o [IClassFactory2](http://msdn.microsoft.com/library/windows/desktop/ms692720) interface.  
  
```
template <class license>
class  CComClassFactory2 : public IClassFactory2,
    public CComObjectRootEx<CComGlobalsThreadModel>,
    public license
```    
  
### <a name="parameters"></a>Parâmetros  
 *licença*  
 Uma classe que implementa as seguintes funções estáticas:  
  
- **VerifyLicenseKey de BOOL estático (BSTR** `bstr` **);**  
  
- **GetLicenseKey de BOOL estático (DWORD** `dwReserved` **, BSTR\***  `pBstr` **);**  
  
- **estático (de IsLicenseValid BOOL);**  
  
### <a name="remarks"></a>Comentários  
 `CComClassFactory2`implementa o [IClassFactory2](http://msdn.microsoft.com/library/windows/desktop/ms692720) interface, que é uma extensão de [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364). **IClassFactory2** controles criação por meio de uma licença do objeto. Uma execução de fábrica de classe em uma máquina licenciada pode fornecer uma chave de licença de tempo de execução. Essa chave de licença permite que um aplicativo de instanciar objetos quando não existe uma licença completa do computador.  
  
 Objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. Para usar `CComClassFactory2`, especifique o [DECLARE_CLASSFACTORY2](#declare_classfactory2) macro na definição de classe do objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#2](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_4.h)]  
  
 **CMyLicense**, o parâmetro de modelo para `CComClassFactory2`, deve implementar as funções estáticas `VerifyLicenseKey`, `GetLicenseKey`, e `IsLicenseValid`. Este é um exemplo de uma classe simples de licença:  
  
 [!code-cpp[NVC_ATL_COM#3](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_5.h)]  
  
 `CComClassFactory2`deriva de ambos **CComClassFactory2Base** e *licença*. **CComClassFactory2Base**, por sua vez, deriva **IClassFactory2** e **CComObjectRootEx\< CComGlobalsThreadModel >**.  
  
##  <a name="declare_classfactory_auto_thread"></a>DECLARE_CLASSFACTORY_AUTO_THREAD  
 Declara [CComClassFactoryAutoThread](../../atl/reference/ccomclassfactoryautothread-class.md) para a classe de fábrica.  
  
```
DECLARE_CLASSFACTORY_AUTO_THREAD()
```  
  
### <a name="remarks"></a>Comentários  
 [CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui o [DECLARE_CLASSFACTORY](#declare_classfactory) macro, que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. No entanto, ao incluir o `DECLARE_CLASSFACTORY_AUTO_THREAD` macro na definição de classe do objeto, você pode substituir esse padrão.  
  
 Quando você cria objetos em vários apartments (em um servidor fora do processo), adicionar `DECLARE_CLASSFACTORY_AUTO_THREAD` à sua classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_6.h)]  
  
##  <a name="ccomclassfactoryautothread_class"></a>Classe CComClassFactoryAutoThread  
 Essa classe implementa o [IClassFactory](http://msdn.microsoft.com/library/windows/desktop/ms694364) de interface e permite que os objetos a serem criados em vários apartments.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
```
class CComClassFactoryAutoThread : public IClassFactory,
public CComObjectRootEx<CComGlobalsThreadModel>
```  
  
### <a name="remarks"></a>Comentários  
 `CComClassFactoryAutoThread`é semelhante a [CComClassFactory](../../atl/reference/ccomclassfactory-class.md), mas permite que os objetos a serem criados em vários apartments. Para aproveitar esse suporte, derivam o seu módulo EXE de [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).  
  
 Objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. Para usar `CComClassFactoryAutoThread`, especifique o [DECLARE_CLASSFACTORY_AUTO_THREAD](#declare_classfactory_auto_thread) macro na definição de classe do objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#9](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_6.h)]  
  
##  <a name="declare_classfactory_singleton"></a>DECLARE_CLASSFACTORY_SINGLETON  
 Declara [CComClassFactorySingleton](../../atl/reference/ccomclassfactorysingleton-class.md) para a classe de fábrica.  
  
```
DECLARE_CLASSFACTORY_SINGLETON( obj )
```  
  
### <a name="parameters"></a>Parâmetros  
 `obj`  
 [in] O nome do seu objeto de classe.  
  
### <a name="remarks"></a>Comentários  
 [CComCoClass](../../atl/reference/ccomcoclass-class.md) inclui o [DECLARE_CLASSFACTORY](#declare_classfactory) macro, que especifica [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) como a fábrica de classe padrão. No entanto, ao incluir o `DECLARE_CLASSFACTORY_SINGLETON` macro na definição de classe do objeto, você pode substituir esse padrão.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_7.h)]  
  
##  <a name="ccomclassfactorysingleton_class"></a>Classe CComClassFactorySingleton  
 Essa classe é derivada de [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
```
template<class T>
class CComClassFactorySingleton : public CComClassFactory
```  
  
### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe.  
  
 `CComClassFactorySingleton`deriva [CComClassFactory](../../atl/reference/ccomclassfactory-class.md) e usa [CComObjectGlobal](../../atl/reference/ccomobjectglobal-class.md) para construir um único objeto. Cada chamada para o `CreateInstance` método simplesmente consulta este objeto para um ponteiro de interface.  
  
### <a name="remarks"></a>Comentários  
 Objetos ATL normalmente adquirem uma fábrica de classes derivando de [CComCoClass](../../atl/reference/ccomcoclass-class.md). Essa classe inclui a macro [DECLARE_CLASSFACTORY](#declare_classfactory), que declara `CComClassFactory` como a fábrica de classe padrão. Para usar `CComClassFactorySingleton`, especifique o [DECLARE_CLASSFACTORY_SINGLETON](#declare_classfactory_singleton) macro na definição de classe do objeto. Por exemplo:  
  
 [!code-cpp[NVC_ATL_COM#10](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_7.h)]  
  
##  <a name="declare_get_controlling_unknown"></a>DECLARE_GET_CONTROLLING_UNKNOWN  
 Declara uma função virtual `GetControllingUnknown`.  
  
```
DECLARE_GET_CONTROLLING_UNKNOWN()
```  
  
### <a name="remarks"></a>Comentários  
 Adicionar esta macro para seu objeto, se você receber a mensagem de erro do compilador que `GetControllingUnknown` é indefinido (por exemplo, em **CComAggregateCreator**).  
  
##  <a name="declare_not_aggregatable"></a>DECLARE_NOT_AGGREGATABLE  
 Especifica que o objeto não pode ser agregado.  
  
```
DECLARE_NOT_AGGREGATABLE( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome do objeto de classe que você está definindo como não agregável.  
  
### <a name="remarks"></a>Comentários  
 `DECLARE_NOT_AGGREGATABLE`faz com que `CreateInstance` para retornar um erro ( **CLASS_E_NOAGGREGATION**) se for feita uma tentativa para agregação em seu objeto.  
  
 Por padrão, [CComCoClass](../../atl/reference/ccomcoclass-class.md) contém o [DECLARE_AGGREGATABLE](#declare_aggregatable) macro, que especifica se o objeto pode ser agregado. Para substituir esse comportamento padrão, inclua `DECLARE_NOT_AGGREGATABLE` em sua definição de classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#121](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_1.h)]  
  
##  <a name="declare_only_aggregatable"></a>DECLARE_ONLY_AGGREGATABLE  
 Especifica que o objeto deve ser agregado.  
  
```
DECLARE_ONLY_AGGREGATABLE( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome do objeto de classe que você está definindo como somente agregável.  
  
### <a name="remarks"></a>Comentários  
 `DECLARE_ONLY_AGGREGATABLE`causa um erro ( **E_FAIL**) se for feita uma tentativa de **CoCreate** seu objeto como objeto agregado.  
  
 Por padrão, [CComCoClass](../../atl/reference/ccomcoclass-class.md) contém o [DECLARE_AGGREGATABLE](#declare_aggregatable) macro, que especifica se o objeto pode ser agregado. Para substituir esse comportamento padrão, inclua `DECLARE_ONLY_AGGREGATABLE` em sua definição de classe.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#125](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_8.h)]  
  
##  <a name="declare_poly_aggregatable"></a>DECLARE_POLY_AGGREGATABLE  
 Especifica que uma instância de **CComPolyObject \<**  *x*  **>**  é criado quando o objeto é criado.  
  
```
DECLARE_POLY_AGGREGATABLE( x )
```  
  
### <a name="parameters"></a>Parâmetros  
 *x*  
 [in] O nome do objeto de classe que você está definindo como agregável ou não agregável.  
  
### <a name="remarks"></a>Comentários  
 Durante a criação, o valor do desconhecido externo é verificado. Se for **nulo**, **IUnknown** é implementada por um objeto agregado. Se o desconhecido externo não é **nulo**, **IUnknown** é implementada por um objeto agregado.  
  
 A vantagem de usar `DECLARE_POLY_AGGREGATABLE` é evitar ter dois `CComAggObject` e `CComObject` em seu módulo para lidar com casos agregados e agregados. Um único `CComPolyObject` objeto lida com ambos os casos. Isso significa que apenas uma cópia do vtable e uma cópia das funções existem em seu módulo. Se seu vtable for grande, isso pode diminuir significativamente o tamanho do módulo. No entanto, se seu vtable for pequeno, usando `CComPolyObject` pode resultar em um tamanho ligeiramente maior do módulo porque ele não é otimizado para um objeto agregado ou agregado, assim como `CComAggObject` e `CComObject`.  
  
 O `DECLARE_POLY_AGGREGATABLE` macro automaticamente é declarada em seu objeto, se você usar o Assistente de controle ATL para criar um controle total.  
  
##  <a name="declare_protect_final_construct"></a>DECLARE_PROTECT_FINAL_CONSTRUCT  

 Impede que o objeto que está sendo excluído se (durante [FinalConstruct](ccomobjectrootex-class.md#finalconstruct)) o objeto agregado interno incrementa a contagem de referência, em seguida, diminui a contagem para 0.  
  
```
DECLARE_PROTECT_FINAL_CONSTRUCT()
```  
  
##  <a name="declare_view_status"></a>DECLARE_VIEW_STATUS  
 Colocar essa macro na classe de controle de um controle ActiveX ATL para especificar o **VIEWSTATUS** sinalizadores para o contêiner.  
  
```
DECLARE_VIEW_STATUS( statusFlags )
```  
  
### <a name="parameters"></a>Parâmetros  
 `statusFlags`  
 [in] O **VIEWSTATUS** sinalizadores. Consulte [VIEWSTATUS](http://msdn.microsoft.com/library/windows/desktop/ms687201) para obter uma lista de sinalizadores.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Windowing#126](../../atl/codesnippet/cpp/aggregation-and-class-factory-macros_9.h)]  
  
## <a name="see-also"></a>Consulte também  
 [Macros](../../atl/reference/atl-macros.md)
