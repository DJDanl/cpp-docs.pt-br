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
ms.openlocfilehash: 515c4e90ee6ab77a6c7c1ae108393ea1aafb7c17
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57304061"
---
# <a name="cobject-class"></a>Classe CObject

A classe base principal para a biblioteca Microsoft Foundation Class.

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
|[CObject::Dump](#dump)|Produz um despejo de diagnóstico deste objeto.|
|[CObject::GetRuntimeClass](#getruntimeclass)|Retorna o `CRuntimeClass` estrutura correspondente à classe do objeto.|
|[CObject::IsKindOf](#iskindof)|Testa a relação do objeto a uma determinada classe.|
|[CObject::IsSerializable](#isserializable)|Testa para ver se esse objeto pode ser serializado.|
|[CObject::Serialize](#serialize)|Carrega ou armazena um objeto de/para um arquivo morto.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Excluir CObject::operator](#operator_delete)|Especial **excluir** operador.|
|[CObject::operator novo](#operator_new)|Especial **novo** operador.|

## <a name="remarks"></a>Comentários

Ela serve como a raiz não apenas para as classes de biblioteca, como `CFile` e `CObList`, mas também para as classes que você escreve. `CObject` fornece serviços básicos, incluindo

- Suporte de serialização

- Informações de classe de tempo de execução

- Saída de diagnóstico do objeto

- Compatibilidade com as classes de coleção

Observe que `CObject` não oferece suporte a várias heranças. Suas classes derivadas podem ter apenas um `CObject` classe base e que `CObject` deve ser mais à esquerda na hierarquia. É permitido, no entanto, ter estruturas e não- `CObject`-classes derivadas no lado direita ramificações de herança múltipla.

Você perceberá maiores benefícios de `CObject` derivação, se você usar algumas das macros opcionais em suas declarações e a implementação da classe.

As macros de primeiro nível [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic) e [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic), permitir o acesso de tempo de execução para o nome de classe e sua posição na hierarquia. Isso, por sua vez, permite que o despejo de diagnóstico significativos.

As macros de segundo nível [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial), incluir toda a funcionalidade das macros de primeiro nível, e eles permitem que um objeto deve ser "serializada" e para um "arquivo".

Para obter informações sobre derivando de classes de C++ e Microsoft Foundation classes em geral e usando `CObject`, consulte [usando CObject](../../mfc/using-cobject.md) e [serialização](../../mfc/serialization-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="assertvalid"></a>  CObject::AssertValid

Valida a integridade desse objeto.

```
virtual void AssertValid() const;
```

### <a name="remarks"></a>Comentários

`AssertValid` executa uma verificação de validade nesse objeto, verificando seu estado interno. Na versão de depuração da biblioteca, `AssertValid` pode declarar e, portanto, encerrar o programa com uma mensagem que lista o número de linha e o nome do arquivo em que a declaração falhou.

Ao escrever sua própria classe, você deve substituir o `AssertValid` função para fornecer serviços de diagnóstico para você e outros usuários da sua classe. Substituído `AssertValid` normalmente, chama o `AssertValid` função da sua classe base antes de verificar se os membros de dados exclusivos para a classe derivada.

Porque `AssertValid` é um **const** função, você não tem permissão para alterar o estado do objeto durante o teste. Sua própria classe derivada `AssertValid` funções não deve lançar exceções, mas em vez disso, deve declarar se eles detectam os dados de objeto inválido.

A definição de "validade" depende da classe do objeto. Como regra, a função deve executar uma "verificação superficial". Ou seja, se um objeto contém ponteiros para outros objetos, ele deve verificar para ver se os ponteiros não forem nulos, mas ele não deve executar testes nos objetos referenciados por ponteiros de validade.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#7](../../mfc/codesnippet/cpp/cobject-class_1.cpp)]

Para obter outro exemplo, consulte [AfxDoForAllObjects](diagnostic-services.md#afxdoforallobjects).

##  <a name="cobject"></a>  CObject::CObject

Essas funções são o padrão `CObject` construtores.

```
CObject();
CObject(const CObject& objectSrc);
```

### <a name="parameters"></a>Parâmetros

*objectSrc*<br/>
Uma referência a outro `CObject`

### <a name="remarks"></a>Comentários

A versão padrão é chamada automaticamente pelo construtor de classe derivada.

Se sua classe seja serializável (incorpora a macro IMPLEMENT_SERIAL), em seguida, você deve ter um construtor padrão (um construtor sem argumentos) na sua declaração de classe. Se você não precisar de um construtor padrão, declarar uma particular ou protegido construtor "empty". Para obter mais informações, consulte [CObject usando](../../mfc/using-cobject.md).

O construtor de cópia padrão do C++ padrão classe faz uma cópia do membro por membro. A presença de particular `CObject` construtor de cópia garante uma mensagem de erro do compilador se o construtor de cópia da sua classe for necessária, mas não está disponível. Portanto, você deve fornecer um construtor de cópia se sua classe exige esse recurso.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usada no `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#8](../../mfc/codesnippet/cpp/cobject-class_2.cpp)]

##  <a name="dump"></a>  CObject::Dump

Despeja o conteúdo de seu objeto para um [CDumpContext](../../mfc/reference/cdumpcontext-class.md) objeto.

```
virtual void Dump(CDumpContext& dc) const;
```

### <a name="parameters"></a>Parâmetros

*dc*<br/>
O contexto de despejo de diagnóstico para despejar, geralmente `afxDump`.

### <a name="remarks"></a>Comentários

Ao escrever sua própria classe, você deve substituir o `Dump` função para fornecer serviços de diagnóstico para você e outros usuários da sua classe. Substituído `Dump` normalmente, chama o `Dump` função da sua classe base antes de imprimir os membros de dados exclusivos para a classe derivada. `CObject::Dump` Imprime o nome de classe, se sua classe usa o `IMPLEMENT_DYNAMIC` ou macro IMPLEMENT_SERIAL.

> [!NOTE]
>  Seu `Dump` função não deve imprimir um caractere de nova linha no final da sua saída.

`Dump` chamadas sentido somente na versão de depuração da biblioteca de classes Microsoft Foundation. Você deve colchete chamadas, declarações de função e implementações de função com **#ifdef DEBUG** /  `#endif` instruções para compilação condicional.

Uma vez que `Dump` é um **const** função, você não tem permissão para alterar o estado do objeto durante o despejo.

O [CDumpContext inserção (<<) operador](../../mfc/reference/cdumpcontext-class.md#operator_lt_lt) chamadas `Dump` quando um `CObject` ponteiro é inserido.

`Dump` permite que apenas "acíclico" despejar de objetos. Por exemplo, você pode despejar uma lista de objetos, mas se um dos objetos é a lista em si, você eventualmente estourar a pilha.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#9](../../mfc/codesnippet/cpp/cobject-class_3.cpp)]

##  <a name="getruntimeclass"></a>  CObject::GetRuntimeClass

Retorna o `CRuntimeClass` estrutura correspondente à classe do objeto.

```
virtual CRuntimeClass* GetRuntimeClass() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura correspondente à classe do objeto; nunca **nulo**.

### <a name="remarks"></a>Comentários

Há um `CRuntimeClass` estrutura de cada `CObject`-classe derivada. Os membros da estrutura são da seguinte maneira:

- **LPCSTR m_lpszClassName** uma cadeia de caracteres terminada em nulo que contém o nome de classe de ASCII.

- **int m_nObjectSize** o tamanho do objeto, em bytes. Se o objeto tiver membros de dados que apontam para a memória alocada, o tamanho do que a memória não está incluído.

- **UINT m_wSchema** o número de esquema (-1 para classes não serializáveis). Consulte a [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro para obter uma descrição do número de esquema.

- **CObject\* (PASCAL\* m_pfnCreateObject) ()** um ponteiro de função para o construtor padrão que cria um objeto de sua classe (válido somente se a classe dá suporte à criação dinâmica; caso contrário, retornará **nulo** ).

- **CRuntimeClass\* (PASCAL\* m_pfn_GetBaseClass) ()** se seu aplicativo está dinamicamente vinculado à versão AFXDLL do MFC, um ponteiro para uma função que retorna o `CRuntimeClass` estrutura da classe base.

- **CRuntimeClass\* m_pBaseClass** se seu aplicativo está vinculado estaticamente ao MFC, um ponteiro para o `CRuntimeClass` estrutura da classe base.

Essa função requer o uso do [IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic), [IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate), ou [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro na implementação da classe. Caso contrário, você obterá resultados incorretos.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#10](../../mfc/codesnippet/cpp/cobject-class_4.cpp)]

##  <a name="iskindof"></a>  CObject::IsKindOf

Testa a relação do objeto a uma determinada classe.

```
BOOL IsKindOf(const CRuntimeClass* pClass) const;
```

### <a name="parameters"></a>Parâmetros

*pClass*<br/>
Um ponteiro para um [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) estrutura associada ao seu `CObject`-classe derivada.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se o objeto corresponde à classe; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Essa função testa *pClass* para ver se (1) é um objeto da classe especificada ou (2) é um objeto de uma classe derivada da classe especificada. Essa função funciona apenas em classes declaradas com o [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic), [DECLARE_DYNCREATE](run-time-object-model-services.md#declare_dyncreate), ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro.

Não use essa função extensivamente porque ela elimina o recurso de polimorfismo de C++. Use funções virtuais.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#11](../../mfc/codesnippet/cpp/cobject-class_5.cpp)]

##  <a name="isserializable"></a>  CObject::IsSerializable

Testa se este objeto está qualificado para a serialização.

```
BOOL IsSerializable() const;
```

### <a name="return-value"></a>Valor de retorno

Diferente de zero se esse objeto pode ser serializado; Caso contrário, 0.

### <a name="remarks"></a>Comentários

Para uma classe seja serializável, sua declaração deve conter o [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro e a implementação devem conter o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro.

> [!NOTE]
>  Não substitua essa função.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#12](../../mfc/codesnippet/cpp/cobject-class_6.cpp)]

##  <a name="operator_delete"></a>  Excluir CObject::operator

Para obter a versão de lançamento da biblioteca, operador **exclua** libera a memória alocada pelo operador **novos**.

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

Na versão de depuração, operador **excluir** participa de um esquema de alocação de monitoramento projetado para detectar vazamentos de memória.

Se você usar a linha de código

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]

antes de qualquer uma das suas implementações em um. CPP, em seguida, a terceira versão de arquivo **excluir** será usado, armazenar o nome de arquivo e número de linha no bloco alocado para relatar posteriormente. Você não precisa se preocupar sobre fornecendo os parâmetros extras; uma macro cuida para você.

Mesmo se você não usa DEBUG_NEW no modo de depuração, você ainda receber a detecção de vazamento, mas sem o número de linha do arquivo de origem reporting descrito acima.

Se você substituir os operadores **novos** e **excluir**, você perder essa funcionalidade de diagnóstico.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usada no `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#15](../../mfc/codesnippet/cpp/cobject-class_8.cpp)]

##  <a name="operator_new"></a>  CObject::operator novo

Para obter a versão de lançamento da biblioteca, operador **novos** realiza uma alocação de memória ideal de uma maneira semelhante ao `malloc`.

```
void* PASCAL operator new(size_t nSize);
void* PASCAL operator new(size_t, void* p);

void* PASCAL operator new(
    size_t nSize,
    LPCSTR lpszFileName,
    int nLine);
```

### <a name="remarks"></a>Comentários

Na versão de depuração, operador **novo** participa de um esquema de alocação de monitoramento projetado para detectar vazamentos de memória.

Se você usar a linha de código

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]

antes de qualquer uma das suas implementações em um. CPP do arquivo, em seguida, a segunda versão do **novo** será usado, armazenar o nome de arquivo e número de linha no bloco alocado para relatar posteriormente. Você não precisa se preocupar sobre fornecendo os parâmetros extras; uma macro cuida para você.

Mesmo se você não usa DEBUG_NEW no modo de depuração, você ainda receber a detecção de vazamento, mas sem o número de linha do arquivo de origem reporting descrito acima.

> [!NOTE]
>  Se você substituir esse operador, você também deve substituir **excluir**. Não use a biblioteca padrão `_new_handler` função.

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usada no `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#16](../../mfc/codesnippet/cpp/cobject-class_9.h)]

##  <a name="serialize"></a>  CObject::Serialize

Lê ou grava este objeto de ou para um arquivo morto.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Um `CArchive` objeto a ser serializado para ou do.

### <a name="remarks"></a>Comentários

Você deve substituir `Serialize` para cada classe que você deseja serializar. Substituído `Serialize` deve primeiro chamar o `Serialize` função da sua classe base.

Você também deve usar o [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro na sua declaração de classe e você deve usar o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro na implementação.

Use [CArchive::IsLoading](../../mfc/reference/carchive-class.md#isloading) ou [CArchive::IsStoring](../../mfc/reference/carchive-class.md#isstoring) para determinar se o arquivo morto é carregar ou armazenar.

`Serialize` é chamado pelo [CArchive::ReadObject](../../mfc/reference/carchive-class.md#readobject) e [CArchive::WriteObject](../../mfc/reference/carchive-class.md#writeobject). Essas funções estão associadas a `CArchive` operador de inserção ( **< \<**) e o operador de extração ( **>>**).

Para obter exemplos de serialização, consulte o artigo [serialização: Serializando um objeto](../../mfc/serialization-serializing-an-object.md).

### <a name="example"></a>Exemplo

Ver [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter uma lista de `CAge` classe usado em todos os `CObject` exemplos.

[!code-cpp[NVC_MFCCObjectSample#13](../../mfc/codesnippet/cpp/cobject-class_10.cpp)]

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
