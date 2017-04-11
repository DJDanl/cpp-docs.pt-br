---
title: Classe CObject | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CObject
- AFX/CObject
- AFX/CObject::CObject
- AFX/CObject::AssertValid
- AFX/CObject::Dump
- AFX/CObject::GetRuntimeClass
- AFX/CObject::IsKindOf
- AFX/CObject::IsSerializable
- AFX/CObject::Serialize
dev_langs:
- C++
helpviewer_keywords:
- base classes, MFC objects
- objects [C++], base class for MFC
- object classes
- CObject class
ms.assetid: 95e9acd3-d9eb-4ac0-b52b-ca4a501a7a3a
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
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: f0b85aa0a297b5961240f10fcb9854a0d3001948
ms.lasthandoff: 04/01/2017

---
# <a name="cobject-class"></a>Classe CObject
A principal classe base para a biblioteca Microsoft Foundation Class.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class AFX_NOVTABLE CObject  
```  
  
## <a name="members"></a>Membros  
  
### <a name="protected-constructors"></a>Construtores Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObject::CObject](#cobject)|Construtor padrão.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CObject::AssertValid](#assertvalid)|Valida a integridade desse objeto.|  
|[CObject::Dump](#dump)|Produz um despejo de diagnóstico do objeto.|  
|[CObject::GetRuntimeClass](#getruntimeclass)|Retorna o `CRuntimeClass` estrutura correspondente à classe do objeto.|  
|[CObject::IsKindOf](#iskindof)|Testa a relação do objeto para uma determinada classe.|  
|[CObject::IsSerializable](#isserializable)|Realiza testes para verificar se este objeto pode ser serializado.|  
|[CObject::Serialize](#serialize)|Carrega ou armazena um objeto de/para um arquivo morto.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[Excluir CObject::operator](#operator_delete)|Especial **excluir** operador.|  
|[CObject::operator novo](#operator_new)|Especial **novo** operador.|  
  
## <a name="remarks"></a>Comentários  
 Ele serve como a raiz não somente para classes de biblioteca como `CFile` e `CObList`, mas também para as classes que você escreve. `CObject`fornece serviços básicos, incluindo  
  
-   Suporte de serialização  
  
-   Informações de classe de tempo de execução  
  
-   Saída de diagnóstico do objeto  
  
-   Compatibilidade com classes de coleção  
  
 Observe que `CObject` não oferece suporte a várias heranças. As classes derivadas podem ter apenas um `CObject` classe base e que `CObject` deve ser mais à esquerda na hierarquia. É permitido, no entanto, para que as estruturas e não- `CObject`-derivado classes no direita ramificações de várias heranças.  
  
 Você vai perceber os benefícios principais do `CObject` derivação se você usar algumas das macros opcionais em sua implementação de classe e declarações.  
  
 As macros de primeiro nível, [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic) e [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic), permitir o acesso de tempo de execução para o nome da classe e sua posição na hierarquia. Isso, por sua vez, permite despejo significativo de diagnóstico.  
  
 As macros de segundo nível, [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial), incluem todas as funcionalidades de macros de primeiro nível, e eles permitem que um objeto a ser "serializado" para e de um "arquivamento".  
  
 Para obter informações sobre derivando de classes de C++ e Microsoft Foundation classes em geral e usando `CObject`, consulte [usando CObject](../../mfc/using-cobject.md) e [serialização](../../mfc/serialization-in-mfc.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `CObject`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** AFX  
  
##  <a name="assertvalid"></a>CObject::AssertValid  
 Valida a integridade desse objeto.  
  
```  
virtual void AssertValid() const;  
```  
  
### <a name="remarks"></a>Comentários  
 `AssertValid`executa uma verificação de validade neste objeto verificando seu estado interno. Na versão de depuração da biblioteca, `AssertValid` pode declarar e, portanto, encerrar o programa com uma mensagem que lista o número de linha e o nome do arquivo onde a asserção falha.  
  
 Quando você escrever sua própria classe, você deve substituir o `AssertValid` função para fornecer serviços de diagnóstico para você e outros usuários da sua classe. Substituído `AssertValid` normalmente chama o `AssertValid` função de sua classe base antes de verificar os membros de dados exclusivos para a classe derivada.  
  
 Porque `AssertValid` é um **const** função, você não tem permissão para alterar o estado do objeto durante o teste. Sua própria classe derivada `AssertValid` funções não deverão gerar exceções, mas em vez disso, deve declarar se detectam os dados de objeto inválido.  
  
 A definição de "validade" depende da classe do objeto. Como regra, a função deve executar uma "verificação superficial". Ou seja, se um objeto contém ponteiros para outros objetos, deve verificar para ver se os ponteiros não forem nulos, mas não deve executar um teste em objetos referenciados por ponteiros de validade.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample #7](../../mfc/codesnippet/cpp/cobject-class_1.cpp)]  
  
 Outro exemplo, consulte [AfxDoForAllObjects](diagnostic-services.md#afxdoforallobjects).  
  
##  <a name="cobject"></a>CObject::CObject  
 Essas funções são o padrão `CObject` construtores.  
  
```  
CObject();  
CObject(const CObject& objectSrc);
```  
  
### <a name="parameters"></a>Parâmetros  
 *objectSrc*  
 Uma referência a outro`CObject`  
  
### <a name="remarks"></a>Comentários  
 A versão padrão é chamada automaticamente pelo construtor de classe derivada.  
  
 Se sua classe serializável (ele incorpora o `IMPLEMENT_SERIAL` macro), em seguida, você deve ter um construtor padrão (um construtor sem argumentos) na sua declaração de classe. Se você não precisar de um construtor padrão, declarar uma particular ou protegido construtor "empty". Para obter mais informações, consulte [usando CObject](../../mfc/using-cobject.md).  
  
 O construtor de cópia padrão do C++ padrão classe faz uma cópia do membro por membro. A presença de particular `CObject` construtor de cópia garante uma mensagem de erro do compilador se o construtor de cópia da sua classe for necessária, mas não está disponível. Portanto, você deve fornecer um construtor de cópia se sua classe exige esse recurso.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada no `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample n º 8](../../mfc/codesnippet/cpp/cobject-class_2.cpp)]  
  
##  <a name="dump"></a>CObject::Dump  
 Despeja o conteúdo do objeto para um [CDumpContext](../../mfc/reference/cdumpcontext-class.md) objeto.  
  
```  
virtual void Dump(CDumpContext& dc) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `dc`  
 O contexto de diagnóstico de despejo para despejar, normalmente `afxDump`.  
  
### <a name="remarks"></a>Comentários  
 Quando você escrever sua própria classe, você deve substituir o `Dump` função para fornecer serviços de diagnóstico para você e outros usuários da sua classe. Substituído `Dump` normalmente chama o `Dump` função de sua classe base antes de imprimir os membros de dados exclusivos para a classe derivada. `CObject::Dump`Imprime o nome da classe, se a classe usa a `IMPLEMENT_DYNAMIC` ou `IMPLEMENT_SERIAL` macro.  
  
> [!NOTE]
>  O `Dump` função não deve imprimir um caractere de nova linha no final de sua saída.  
  
 `Dump`chamadas fazem sentido somente na versão de depuração da biblioteca Microsoft Foundation Class. Você deve colchete chamadas, declarações de função e implementações de função com **#ifdef DEBUG** /  `#endif` instruções para compilação condicional.  
  
 Como `Dump` é um **const** função, você não tem permissão para alterar o estado do objeto durante o despejo de memória.  
  
 O [CDumpContext inserção (<)> </)> ](../../mfc/reference/cdumpcontext-class.md#operator_lt_lt) chamadas `Dump` quando um `CObject` ponteiro é inserido.  
  
 `Dump`permite somente "acíclico" despejo de objetos. Por exemplo, o despejo de uma lista de objetos, mas se um dos objetos é a lista em si, você eventualmente estourar a pilha.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample n º 9](../../mfc/codesnippet/cpp/cobject-class_3.cpp)]  
  
##  <a name="getruntimeclass"></a>CObject::GetRuntimeClass  
 Retorna o `CRuntimeClass` estrutura correspondente à classe do objeto.  
  
```  
virtual CRuntimeClass* GetRuntimeClass() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura correspondente à classe do objeto; nunca **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Há um `CRuntimeClass` estrutura para cada `CObject`-classe derivada. Os membros de estrutura são da seguinte maneira:  
  
- **LPCSTR m_lpszClassName** uma cadeia de caracteres terminada em nulo que contém o nome da classe ASCII.  
  
- **int m_nObjectSize** o tamanho do objeto, em bytes. Se o objeto tiver membros de dados que aponte para a memória alocada, o tamanho da memória não está incluído.  
  
- **UINT m_wSchema** o número de esquema (-1 para classes nonserializable). Consulte o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro para obter uma descrição do número de esquema.  
  
- **CObject\* (PASCAL\* m_pfnCreateObject) ()** um ponteiro de função para o construtor padrão que cria um objeto de classe (válido somente se a classe oferece suporte à criação dinâmica; caso contrário, retornará **nulo**).  
  
- **CRuntimeClass\* (PASCAL\* m_pfn_GetBaseClass) ()** se seu aplicativo está dinamicamente vinculado à versão AFXDLL do MFC, um ponteiro para uma função que retorna o `CRuntimeClass` estrutura da classe base.  
  
- **CRuntimeClass\* m_pBaseClass** se seu aplicativo está estaticamente vinculado ao MFC, um ponteiro para o `CRuntimeClass` estrutura da classe base.  
  
 Essa função requer o uso do [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic), [IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate), ou [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro na implementação da classe. Caso contrário, você obterá resultados incorretos.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample #10](../../mfc/codesnippet/cpp/cobject-class_4.cpp)]  
  
##  <a name="iskindof"></a>CObject::IsKindOf  
 Testa a relação do objeto para uma determinada classe.  
  
```  
BOOL IsKindOf(const CRuntimeClass* pClass) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pClass`  
 Um ponteiro para um [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura associada a sua `CObject`-classe derivada.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o objeto corresponde à classe; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função testa `pClass` se (1) é um objeto da classe especificada ou (2) é um objeto de uma classe derivada da classe especificada. Essa função funciona somente para classes declaradas com o [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic), [DECLARE_DYNCREATE](run-time-object-model-services.md#declare_dyncreate), ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro.  
  
 Não use essa função extensivamente porque ele anula o recurso do C++ polimorfismo. Use funções virtuais.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample n º 11](../../mfc/codesnippet/cpp/cobject-class_5.cpp)]  
  
##  <a name="isserializable"></a>CObject::IsSerializable  
 Testa se este objeto é elegível para serialização.  
  
```  
BOOL IsSerializable() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se este objeto pode ser serializado; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Uma classe ser serializável, sua declaração deve conter o [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro e a implementação devem conter o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro.  
  
> [!NOTE]
>  Não substitua essa função.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample #12](../../mfc/codesnippet/cpp/cobject-class_6.cpp)]  
  
##  <a name="operator_delete"></a>Excluir CObject::operator  
 Para a versão da biblioteca do operador **excluir** libera a memória alocada pelo operador **novo**.  
  
```  
void PASCAL operator delete(void* p);

 
void PASCAL operator delete(
    void* p,
    void* pPlace);

 
void PASCAL operator delete(
    void* p,  
    LPCSTR lpszFileName,  
    int nLine);
```  
  
### <a name="remarks"></a>Comentários  
 Na versão de depuração, operador **excluir** participa de um esquema de alocação de monitoramento detecta perdas de memória.  
  
 Se você usar a linha de código  
  
 [!code-cpp[NVC_MFCCObjectSample #14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]  
  
 antes de qualquer uma das suas implementações em uma. CPP arquivo, em seguida, a terceira versão do **excluir** será usado, armazenar o nome de arquivo e número de linha no bloco alocado para relatar posteriormente. Você não precisa se preocupar sobre fornecendo os parâmetros extras; uma macro encarrega para você.  
  
 Mesmo se você não usar `DEBUG_NEW` no modo de depuração, você ainda receber vazamento de detecção, mas sem o relatório de número de linha do arquivo de origem descrito acima.  
  
 Se você substituir os operadores **novo** e **excluir**, anular esse recurso de diagnóstico.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada no `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample #15](../../mfc/codesnippet/cpp/cobject-class_8.cpp)]  
  
##  <a name="operator_new"></a>CObject::operator novo  
 Para a versão da biblioteca do operador **novo** executa uma alocação de memória ideal de forma semelhante ao `malloc`.  
  
```  
void* PASCAL operator new(size_t nSize);  
void* PASCAL operator new(size_t, void* p);

 
void* PASCAL operator new(
    size_t nSize,  
    LPCSTR lpszFileName,  
    int nLine);
```  
  
### <a name="remarks"></a>Comentários  
 Na versão de depuração, operador **novo** participa de um esquema de alocação de monitoramento detecta perdas de memória.  
  
 Se você usar a linha de código  
  
 [!code-cpp[NVC_MFCCObjectSample #14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]  
  
 antes de qualquer uma das suas implementações em uma. CPP arquivo, em seguida, a segunda versão do **novo** será usado, armazenar o nome de arquivo e número de linha no bloco alocado para relatar posteriormente. Você não precisa se preocupar sobre fornecendo os parâmetros extras; uma macro encarrega para você.  
  
 Mesmo se você não usar `DEBUG_NEW` no modo de depuração, você ainda receber vazamento de detecção, mas sem o relatório de número de linha do arquivo de origem descrito acima.  
  
> [!NOTE]
>  Se você substituir esse operador, você também deverá substituir **excluir**. Não use a biblioteca padrão **_new_handler** função.  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada no `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample n º 16](../../mfc/codesnippet/cpp/cobject-class_9.h)]  
  
##  <a name="serialize"></a>CObject::Serialize  
 Lê ou grava este objeto de ou para um arquivo morto.  
  
```  
virtual void Serialize(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 `ar`  
 Um `CArchive` objeto a ser serializado para ou do.  
  
### <a name="remarks"></a>Comentários  
 Você deve substituir `Serialize` para cada classe que deseja serializar. Substituído `Serialize` deve primeiro chamar o `Serialize` função de sua classe base.  
  
 Você também deve usar o [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro em sua declaração de classe e você deve usar o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro na implementação.  
  
 Use [CArchive::IsLoading](../../mfc/reference/carchive-class.md#isloading) ou [CArchive::IsStoring](../../mfc/reference/carchive-class.md#isstoring) para determinar se o arquivo é carregar ou armazenar.  
  
 `Serialize`é chamado pelo [CArchive::ReadObject](../../mfc/reference/carchive-class.md#readobject) e [CArchive::WriteObject](../../mfc/reference/carchive-class.md#writeobject). Essas funções são associadas a `CArchive` operador de inserção ( **< \<**) e o operador de extração ( **>>**).  
  
 Para obter exemplos de serialização, consulte o artigo [serialização: serializando um objeto](../../mfc/serialization-serializing-an-object.md).  
  
### <a name="example"></a>Exemplo  
 Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.  
  
 [!code-cpp[NVC_MFCCObjectSample 13](../../mfc/codesnippet/cpp/cobject-class_10.cpp)]  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)




