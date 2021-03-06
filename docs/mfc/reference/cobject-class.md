---
title: Classe CObject
ms.date: 11/04/2016
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
helpviewer_keywords:
- CObject [MFC], CObject
- CObject [MFC], AssertValid
- CObject [MFC], Dump
- CObject [MFC], GetRuntimeClass
- CObject [MFC], IsKindOf
- CObject [MFC], IsSerializable
- CObject [MFC], Serialize
ms.assetid: 95e9acd3-d9eb-4ac0-b52b-ca4a501a7a3a
ms.openlocfilehash: ce745e0717e36a3c9acb5323d04545c59750add7
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222895"
---
# <a name="cobject-class"></a>Classe CObject

A classe base principal para o biblioteca MFC.

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
|[CObject::AssertValid](#assertvalid)|Valida a integridade do objeto.|
|[CObject::D UMP](#dump)|Produz um despejo de diagnóstico deste objeto.|
|[CObject::GetRuntimeClass](#getruntimeclass)|Retorna a `CRuntimeClass` estrutura correspondente à classe desse objeto.|
|[CObject::IsKindOf](#iskindof)|Testa a relação deste objeto com uma determinada classe.|
|[CObject:: IsSerializable](#isserializable)|Testa para ver se este objeto pode ser serializado.|
|[CObject:: Serialize](#serialize)|Carrega ou armazena um objeto de/para um arquivo morto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObject:: Operator Delete](#operator_delete)|**`delete`** Operador especial.|
|[Novo operador CObject:: Operator](#operator_new)|**`new`** Operador especial.|

## <a name="remarks"></a>Comentários

Ele serve como a raiz não apenas para classes de biblioteca, como `CFile` e `CObList` , mas também para as classes que você escreve. `CObject`fornece serviços básicos, incluindo

- Suporte à serialização

- Informações de classe de tempo de execução

- Saída de diagnóstico de objeto

- Compatibilidade com classes de coleção

Observe que `CObject` o não oferece suporte a várias heranças. Suas classes derivadas podem ter apenas uma `CObject` classe base e `CObject` devem estar na extrema esquerda na hierarquia. No entanto, é permitido ter estruturas e `CObject` classes não derivadas em ramificações de múltiplas heranças à direita.

Você perceberá os principais benefícios da `CObject` derivação se usar algumas das macros opcionais em sua implementação e declarações de classe.

As macros de primeiro nível, [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic) e [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic), permitem o acesso em tempo de execução ao nome da classe e sua posição na hierarquia. Isso, por sua vez, permite um despejo de diagnóstico significativo.

As macros de segundo nível, [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial), incluem toda a funcionalidade das macros de primeiro nível e permitem que um objeto seja "serializado" de e para um "arquivo".

Para obter informações sobre como derivar classes do Microsoft Foundation e classes C++ em geral e usando `CObject` , consulte [usando CObject](../../mfc/using-cobject.md) e [serialização](../../mfc/serialization-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

## <a name="cobjectassertvalid"></a><a name="assertvalid"></a>CObject::AssertValid

Valida a integridade do objeto.

```
virtual void AssertValid() const;
```

### <a name="remarks"></a>Comentários

`AssertValid`executa uma verificação de validade nesse objeto verificando seu estado interno. Na versão de depuração da biblioteca, `AssertValid` pode declarar e, portanto, encerrar o programa com uma mensagem que lista o número de linha e o nome de arquivo em que a asserção falhou.

Ao escrever sua própria classe, você deve substituir a `AssertValid` função para fornecer serviços de diagnóstico para si mesmo e outros usuários da sua classe. O substituído `AssertValid` normalmente chama a `AssertValid` função de sua classe base antes de verificar os membros de dados exclusivos para a classe derivada.

Como `AssertValid` é uma **`const`** função, você não tem permissão para alterar o estado do objeto durante o teste. Suas próprias funções de classe derivada `AssertValid` não devem gerar exceções, mas sim deve declarar se detectam dados de objeto inválido.

A definição de "validade" depende da classe do objeto. Como regra, a função deve executar uma "verificação superficial". Ou seja, se um objeto contiver ponteiros para outros objetos, ele deverá verificar se os ponteiros não são nulos, mas não deve executar testes de validade nos objetos referenciados pelos ponteiros.

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#7](../../mfc/codesnippet/cpp/cobject-class_1.cpp)]

Para obter outro exemplo, consulte [AfxDoForAllObjects](diagnostic-services.md#afxdoforallobjects).

## <a name="cobjectcobject"></a><a name="cobject"></a>CObject::CObject

Essas funções são os `CObject` construtores padrão.

```
CObject();
CObject(const CObject& objectSrc);
```

### <a name="parameters"></a>parâmetros

*objectSrc*<br/>
Uma referência a outro`CObject`

### <a name="remarks"></a>Comentários

A versão padrão é chamada automaticamente pelo construtor de sua classe derivada.

Se sua classe for serializável (incorpora a macro IMPLEMENT_SERIAL), você deverá ter um construtor padrão (um construtor sem argumentos) em sua declaração de classe. Se você não precisar de um construtor padrão, declare um construtor "vazio" privado ou protegido. Para obter mais informações, consulte [usando CObject](../../mfc/using-cobject.md).

O construtor padrão de cópia de classe padrão C++ faz uma cópia membro por membro. A presença do construtor de `CObject` cópia privada garante uma mensagem de erro do compilador se o construtor de cópia da sua classe for necessário, mas não estiver disponível. Portanto, você deve fornecer um construtor de cópia se sua classe exigir esse recurso.

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada nos `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#8](../../mfc/codesnippet/cpp/cobject-class_2.cpp)]

## <a name="cobjectdump"></a><a name="dump"></a>CObject::D UMP

Despeja o conteúdo do objeto em um objeto [CDumpContext](../../mfc/reference/cdumpcontext-class.md) .

```
virtual void Dump(CDumpContext& dc) const;
```

### <a name="parameters"></a>parâmetros

*origem*<br/>
O contexto de despejo de diagnóstico para despejo, geralmente `afxDump` .

### <a name="remarks"></a>Comentários

Ao escrever sua própria classe, você deve substituir a `Dump` função para fornecer serviços de diagnóstico para si mesmo e outros usuários da sua classe. O substituído `Dump` normalmente chama a `Dump` função de sua classe base antes de imprimir membros de dados exclusivos para a classe derivada. `CObject::Dump`imprime o nome da classe se sua classe usa a `IMPLEMENT_DYNAMIC` macro ou IMPLEMENT_SERIAL.

> [!NOTE]
> Sua `Dump` função não deve imprimir um caractere de nova linha no final de sua saída.

`Dump`as chamadas fazem sentido apenas na versão de depuração do biblioteca MFC. Você deve chamar chamadas de colchete, declarações de função e implementações de função com **#ifdef _DEBUG** /  `#endif` instruções para compilação condicional.

Como `Dump` é uma **`const`** função, você não tem permissão para alterar o estado do objeto durante o despejo.

O [operador de inserção CDumpContext (<<)](../../mfc/reference/cdumpcontext-class.md#operator_lt_lt) chama `Dump` quando um `CObject` ponteiro é inserido.

`Dump`permite apenas despejo de objetos "acíclico". Você pode despejar uma lista de objetos, por exemplo, mas se um dos objetos for a própria lista, você eventualmente excederá a pilha.

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#9](../../mfc/codesnippet/cpp/cobject-class_3.cpp)]

## <a name="cobjectgetruntimeclass"></a><a name="getruntimeclass"></a>CObject::GetRuntimeClass

Retorna a `CRuntimeClass` estrutura correspondente à classe desse objeto.

```
virtual CRuntimeClass* GetRuntimeClass() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) correspondente à classe desse objeto; Nunca **nulo**.

### <a name="remarks"></a>Comentários

Há uma `CRuntimeClass` estrutura para cada `CObject` classe derivada. Os membros da estrutura são os seguintes:

- **M_lpszClassName LPCSTR** Uma cadeia de caracteres terminada em nulo que contém o nome da classe ASCII.

- **m_nObjectSize int** O tamanho do objeto, em bytes. Se o objeto tiver membros de dados que apontam para a memória alocada, o tamanho dessa memória não será incluído.

- **M_wSchema uint** O número do esquema (-1 para classes não serializáveis). Consulte a macro [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) para obter uma descrição do número do esquema.

- **CObject \* (Pascal \* m_pfnCreateObject) ()** um ponteiro de função para o construtor padrão que cria um objeto de sua classe (válido somente se a classe oferecer suporte à criação dinâmica; caso contrário, retornará **NULL**).

- **CRuntimeClass \* (Pascal \* m_pfn_GetBaseClass) ()** se seu aplicativo estiver vinculado dinamicamente à versão AFXDLL do MFC, um ponteiro para uma função que retorna a `CRuntimeClass` estrutura da classe base.

- **CRuntimeClass \* m_pBaseClass** se seu aplicativo estiver vinculado estaticamente ao MFC, um ponteiro para a `CRuntimeClass` estrutura da classe base.

Essa função requer o uso da macro [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic), [IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate)ou [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) na implementação da classe. Caso contrário, você receberá resultados incorretos.

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#10](../../mfc/codesnippet/cpp/cobject-class_4.cpp)]

## <a name="cobjectiskindof"></a><a name="iskindof"></a>CObject::IsKindOf

Testa a relação deste objeto com uma determinada classe.

```
BOOL IsKindOf(const CRuntimeClass* pClass) const;
```

### <a name="parameters"></a>parâmetros

*pClass*<br/>
Um ponteiro para uma estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) associada à sua `CObject` classe derivada.

### <a name="return-value"></a>Valor retornado

Diferente de zero se o objeto corresponder à classe; caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função testa *pClass* para ver se (1) é um objeto da classe especificada ou (2) é um objeto de uma classe derivada da classe especificada. Essa função funciona apenas para classes declaradas com a [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic), [DECLARE_DYNCREATE](run-time-object-model-services.md#declare_dyncreate)ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro.

Não use essa função extensivamente porque ela derrota o recurso polimorfismo do C++. Em vez disso, use as funções virtuais.

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#11](../../mfc/codesnippet/cpp/cobject-class_5.cpp)]

## <a name="cobjectisserializable"></a><a name="isserializable"></a>CObject:: IsSerializable

Testa se este objeto é elegível para serialização.

```
BOOL IsSerializable() const;
```

### <a name="return-value"></a>Valor retornado

Diferente de zero se este objeto puder ser serializado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para que uma classe seja serializável, sua declaração deve conter a macro [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) e a implementação deve conter a macro [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) .

> [!NOTE]
> Não substitua essa função.

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#12](../../mfc/codesnippet/cpp/cobject-class_6.cpp)]

## <a name="cobjectoperator-delete"></a><a name="operator_delete"></a>CObject:: Operator Delete

Para a versão de lançamento da biblioteca, **`delete`** o operador libera a memória alocada pelo operador **`new`** .

```cpp
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

Na versão de depuração, o operador **`delete`** participa de um esquema de monitoramento de alocação projetado para detectar vazamentos de memória.

Se você usar a linha de código

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]

antes de qualquer uma de suas implementações em um. O arquivo CPP, a terceira versão do **`delete`** será usada, armazenando o nome do arquivo e o número da linha no bloco alocado para relatórios posteriores. Você não precisa se preocupar em fornecer os parâmetros extras; uma macro cuida disso para você.

Mesmo que você não use DEBUG_NEW no modo de depuração, ainda terá a detecção de vazamentos, mas sem o relatório de número de linha de arquivo de origem descrito acima.

Se você substituir operadores **`new`** e **`delete`** perder esse recurso de diagnóstico.

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada nos `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#15](../../mfc/codesnippet/cpp/cobject-class_8.cpp)]

## <a name="cobjectoperator-new"></a><a name="operator_new"></a>Novo operador CObject:: Operator

Para a versão de lançamento da biblioteca, **`new`** o operador executa uma alocação de memória ideal de maneira semelhante a `malloc` .

```cpp
void* PASCAL operator new(size_t nSize);
void* PASCAL operator new(size_t, void* p);

void* PASCAL operator new(
    size_t nSize,
    LPCSTR lpszFileName,
    int nLine);
```

### <a name="remarks"></a>Comentários

Na versão de depuração, o operador **`new`** participa de um esquema de monitoramento de alocação projetado para detectar vazamentos de memória.

Se você usar a linha de código

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]

antes de qualquer uma de suas implementações em um. Arquivo CPP, a segunda versão do **`new`** será usada, armazenando o nome do arquivo e o número da linha no bloco alocado para relatórios posteriores. Você não precisa se preocupar em fornecer os parâmetros extras; uma macro cuida disso para você.

Mesmo que você não use DEBUG_NEW no modo de depuração, ainda terá a detecção de vazamentos, mas sem o relatório de número de linha de arquivo de origem descrito acima.

> [!NOTE]
> Se você substituir esse operador, também deverá substituir **`delete`** . Não use a função de biblioteca padrão `_new_handler` .

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada nos `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#16](../../mfc/codesnippet/cpp/cobject-class_9.h)]

## <a name="cobjectserialize"></a><a name="serialize"></a>CObject:: Serialize

Lê ou grava esse objeto de ou para um arquivo.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>parâmetros

*multi-hop*<br/>
Um `CArchive` objeto para o qual serializar.

### <a name="remarks"></a>Comentários

Você deve substituir `Serialize` para cada classe que pretende serializar. O substituído `Serialize` deve primeiro chamar a `Serialize` função de sua classe base.

Você também deve usar a macro [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) em sua declaração de classe e deve usar a macro [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) na implementação.

Use [CArchive:: Isuploading](../../mfc/reference/carchive-class.md#isloading) ou [CArchive:: isarmazening](../../mfc/reference/carchive-class.md#isstoring) para determinar se o arquivo está carregando ou armazenando.

`Serialize`é chamado por [CArchive:: ReadObject](../../mfc/reference/carchive-class.md#readobject) e [CArchive:: WriteObject](../../mfc/reference/carchive-class.md#writeobject). Essas funções são associadas ao `CArchive` operador de inserção ( **<\<**) and extraction operator ( **>>** ).

Para obter exemplos de serialização, consulte o artigo [serialização: Serializando um objeto](../../mfc/serialization-serializing-an-object.md).

### <a name="example"></a>Exemplo

Consulte [CObList:: CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista da `CAge` classe usada em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#13](../../mfc/codesnippet/cpp/cobject-class_10.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)
