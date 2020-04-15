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
ms.openlocfilehash: cea4d09a1c1a4680b095a40fa0619287959ff4ce
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81360420"
---
# <a name="cobject-class"></a>Classe CObject

A classe base principal da Biblioteca de Classes da Microsoft Foundation.

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
|[CObject::AssertValid](#assertvalid)|Valida a integridade deste objeto.|
|[CObject::Dump](#dump)|Produz um despejo de diagnóstico deste objeto.|
|[CObject::GetRuntimeClass](#getruntimeclass)|Retorna `CRuntimeClass` a estrutura correspondente à classe deste objeto.|
|[CObject::IsKindOf](#iskindof)|Testa a relação deste objeto com uma determinada classe.|
|[CObject::IsSerializable](#isserializable)|Teste para ver se esse objeto pode ser serializado.|
|[CObject::Serialize](#serialize)|Carrega ou armazena um objeto de/para um arquivo.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObject::exclusão do operador](#operator_delete)|Operador de **exclusão** especial.|
|[CObject::novo operador](#operator_new)|Novo **new** operador especial.|

## <a name="remarks"></a>Comentários

Ele serve como a raiz não `CFile` apenas `CObList`para as aulas de biblioteca, como e , mas também para as classes que você escreve. `CObject`fornece serviços básicos, incluindo

- Suporte à serialização

- Informações da classe de tempo de execução

- Saída de diagnóstico de objeto

- Compatibilidade com as classes de coleta

Note `CObject` que não suporta herança múltipla. Suas classes derivadas podem `CObject` ter apenas `CObject` uma classe base, e isso deve ser deixado mais à esquerda na hierarquia. É permitido, no entanto, ter estruturas `CObject`e classes não derivadas em ramos de herança múltipla à direita.

Você perceberá grandes `CObject` benefícios da derivação se você usar algumas das macros opcionais em sua implementação de classe e declarações.

As macros de primeiro nível, [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic) e [IMPLEMENT_DYNAMIC,](run-time-object-model-services.md#implement_dynamic)permitem o acesso em tempo de execução ao nome da classe e sua posição na hierarquia. Isso, por sua vez, permite um dumping diagnóstico significativo.

As macros de segundo nível, [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) e [IMPLEMENT_SERIAL,](run-time-object-model-services.md#implement_serial)incluem todas as funcionalidades das macros de primeiro nível e permitem que um objeto seja "serializado" de e para um "arquivo".

Para obter informações sobre as classes da Microsoft Foundation `CObject`e as classes C++ em geral e usando, consulte [Usando CObject](../../mfc/using-cobject.md) e [Serialization](../../mfc/serialization-in-mfc.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CObject`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cobjectassertvalid"></a><a name="assertvalid"></a>CObject::AssertValid

Valida a integridade deste objeto.

```
virtual void AssertValid() const;
```

### <a name="remarks"></a>Comentários

`AssertValid`realiza uma verificação de validade neste objeto verificando seu estado interno. Na versão Debug da `AssertValid` biblioteca, pode afirmar e, assim, encerrar o programa com uma mensagem que lista o número da linha e o nome do arquivo onde a afirmação falhou.

Quando você escreve sua própria classe, `AssertValid` você deve substituir a função para fornecer serviços de diagnóstico para si mesmo e outros usuários de sua classe. O substituído `AssertValid` geralmente chama `AssertValid` a função de sua classe base antes de verificar os membros de dados exclusivos da classe derivada.

Por `AssertValid` ser uma função **const,** você não tem permissão para alterar o estado do objeto durante o teste. Suas próprias `AssertValid` funções de classe derivadas não devem lançar exceções, mas devem afirmar se detectam dados de objetos inválidos.

A definição de "validade" depende da classe do objeto. Como regra geral, a função deve realizar uma "verificação superficial". Ou seja, se um objeto contém ponteiros para outros objetos, ele deve verificar se os ponteiros não são nulos, mas não deve realizar testes de validade nos objetos referidos pelos ponteiros.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada em todos os exemplos.

[!code-cpp[NVC_MFCCObjectSample#7](../../mfc/codesnippet/cpp/cobject-class_1.cpp)]

Em outro exemplo, consulte [AfxDoForAllObjects](diagnostic-services.md#afxdoforallobjects).

## <a name="cobjectcobject"></a><a name="cobject"></a>CObject::CObject

Essas funções são `CObject` os construtores padrão.

```
CObject();
CObject(const CObject& objectSrc);
```

### <a name="parameters"></a>Parâmetros

*objectSrc*<br/>
Uma referência a outro`CObject`

### <a name="remarks"></a>Comentários

A versão padrão é automaticamente chamada pelo construtor de sua classe derivada.

Se sua classe for serializável (ela incorpora a IMPLEMENT_SERIAL macro), então você deve ter um construtor padrão (um construtor sem argumentos) em sua declaração de classe. Se você não precisar de um construtor padrão, declare um construtor privado ou protegido "vazio". Para obter mais informações, consulte [Usando CObject](../../mfc/using-cobject.md).

O construtor padrão de cópia de classe C++ faz uma cópia membro por membro. A presença do `CObject` construtor de cópias privada garante uma mensagem de erro do compilador se o construtor de cópias da sua classe for necessário, mas não estiver disponível. Portanto, você deve fornecer um construtor de cópias se sua classe exigir essa capacidade.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada nos exemplos.

[!code-cpp[NVC_MFCCObjectSample#8](../../mfc/codesnippet/cpp/cobject-class_2.cpp)]

## <a name="cobjectdump"></a><a name="dump"></a>CObject::Dump

Despeja o conteúdo do seu objeto em um objeto [CDumpContext.](../../mfc/reference/cdumpcontext-class.md)

```
virtual void Dump(CDumpContext& dc) const;
```

### <a name="parameters"></a>Parâmetros

*Dc*<br/>
O contexto de despejo `afxDump`diagnóstico para dumping, geralmente .

### <a name="remarks"></a>Comentários

Quando você escreve sua própria classe, `Dump` você deve substituir a função para fornecer serviços de diagnóstico para si mesmo e outros usuários de sua classe. O substituído `Dump` geralmente chama `Dump` a função de sua classe base antes de imprimir membros de dados exclusivos da classe derivada. `CObject::Dump`imprime o nome da `IMPLEMENT_DYNAMIC` classe se sua classe usar a macro ou IMPLEMENT_SERIAL.

> [!NOTE]
> Sua `Dump` função não deve imprimir um caractere newline no final de sua saída.

`Dump`chamadas fazem sentido apenas na versão Debug da Microsoft Foundation Class Library. Você deve fazer chamadas de suporte, declarações de função e implementações de funções com **#ifdef _DEBUG** /  `#endif` declarações para compilação condicional.

Uma `Dump` vez que é uma função **const,** você não está autorizado a alterar o estado do objeto durante o despejo.

O [operador de inserção CDumpContext (<<)](../../mfc/reference/cdumpcontext-class.md#operator_lt_lt) chama `Dump` quando um `CObject` ponteiro é inserido.

`Dump`permite apenas o despejo "acíclico" de objetos. Você pode despejar uma lista de objetos, por exemplo, mas se um dos objetos for a própria lista, você eventualmente transbordará a pilha.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada em todos os exemplos.

[!code-cpp[NVC_MFCCObjectSample#9](../../mfc/codesnippet/cpp/cobject-class_3.cpp)]

## <a name="cobjectgetruntimeclass"></a><a name="getruntimeclass"></a>CObject::GetRuntimeClass

Retorna `CRuntimeClass` a estrutura correspondente à classe deste objeto.

```
virtual CRuntimeClass* GetRuntimeClass() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para a estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) correspondente à classe deste objeto; nunca **NULO**.

### <a name="remarks"></a>Comentários

Há uma `CRuntimeClass` estrutura `CObject`para cada classe derivada. Os membros da estrutura são os seguintes:

- **M_lpszClassName LPCSTR** Uma seqüência de terminadas nula contendo o nome da classe ASCII.

- **int m_nObjectSize** O tamanho do objeto, em bytes. Se o objeto tiver membros de dados que apontam para a memória alocada, o tamanho dessa memória não será incluído.

- **UINT m_wSchema** O número do esquema ( - 1 para classes não seriais). Consulte a [macro IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) para obter uma descrição do número do esquema.

- **CObject\* (\* PASCAL m_pfnCreateObject )( )** Um ponteiro de função para o construtor padrão que cria um objeto de sua classe (válido apenas se a classe suportar criação dinâmica; caso contrário, retorna **NULL**).

- **CRuntimeClass\* (\* PASCAL m_pfn_GetBaseClass ))** Se o seu aplicativo estiver dinamicamente vinculado à versão AFXDLL do MFC, um ponteiro para uma função que retorna a `CRuntimeClass` estrutura da classe base.

- **CRuntimeClass\* m_pBaseClass** Se o aplicativo estiver estático ligado `CRuntimeClass` ao MFC, um ponteiro para a estrutura da classe base.

Esta função requer o uso da [IMPLEMENT_DYNAMIC,](run-time-object-model-services.md#implement_dynamic) [IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate)ou [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro na implementação da classe. Você terá resultados incorretos de outra forma.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada em todos os exemplos.

[!code-cpp[NVC_MFCCObjectSample#10](../../mfc/codesnippet/cpp/cobject-class_4.cpp)]

## <a name="cobjectiskindof"></a><a name="iskindof"></a>CObject::IsKindOf

Testa a relação deste objeto com uma determinada classe.

```
BOOL IsKindOf(const CRuntimeClass* pClass) const;
```

### <a name="parameters"></a>Parâmetros

*pClass*<br/>
Um ponteiro para uma estrutura [CRuntimeClass](../../mfc/reference/cruntimeclass-structure.md) associada à sua `CObject`classe derivada.

### <a name="return-value"></a>Valor retornado

Não zero se o objeto corresponder à classe; caso contrário, 0.

### <a name="remarks"></a>Comentários

Esta função testa *pClass* para ver se (1) é um objeto da classe especificada ou (2) é um objeto de uma classe derivada da classe especificada. Esta função funciona apenas para classes declaradas com o [DECLARE_DYNAMIC](run-time-object-model-services.md#declare_dynamic), [DECLARE_DYNCREATE](run-time-object-model-services.md#declare_dyncreate)ou [DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) macro.

Não use essa função extensivamente porque derrota o recurso de polimorfismo C++. Use funções virtuais em vez disso.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada em todos os exemplos.

[!code-cpp[NVC_MFCCObjectSample#11](../../mfc/codesnippet/cpp/cobject-class_5.cpp)]

## <a name="cobjectisserializable"></a><a name="isserializable"></a>CObject::IsSerializable

Testa se esse objeto é elegível para serialização.

```
BOOL IsSerializable() const;
```

### <a name="return-value"></a>Valor retornado

Não zero se este objeto pode ser serializado; caso contrário, 0.

### <a name="remarks"></a>Comentários

Para que uma classe seja serializável, sua declaração deve conter a [macro DECLARE_SERIAL,](run-time-object-model-services.md#declare_serial) e a implementação deve conter a [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro.

> [!NOTE]
> Não anular esta função.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada em todos os exemplos.

[!code-cpp[NVC_MFCCObjectSample#12](../../mfc/codesnippet/cpp/cobject-class_6.cpp)]

## <a name="cobjectoperator-delete"></a><a name="operator_delete"></a>CObject::exclusão do operador

Para a versão Desemver da biblioteca, o operador **exclui** a memória alocada pelo **operador novo**.

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

Na versão Debug, a **exclusão** do operador participa de um esquema de monitoramento de alocação projetado para detectar vazamentos de memória.

Se você usar a linha de código

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]

antes de qualquer uma de suas implementações em um . Arquivo CPP, em seguida, a terceira versão de **exclusão** será usada, armazenando o nome do arquivo e o número de linha no bloco alocado para relatórios posteriores. Você não precisa se preocupar em fornecer os parâmetros extras; uma macro cuida disso para você.

Mesmo que você não use DEBUG_NEW no modo Debug, você ainda terá detecção de vazamento, mas sem o relatório de número de linha de arquivo de origem descrito acima.

Se você substituir os operadores **novos** e **excluir,** você perderá esse recurso de diagnóstico.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada nos exemplos.

[!code-cpp[NVC_MFCCObjectSample#15](../../mfc/codesnippet/cpp/cobject-class_8.cpp)]

## <a name="cobjectoperator-new"></a><a name="operator_new"></a>CObject::novo operador

Para a versão Desemver da biblioteca, o **operador** `malloc`novo executa uma alocação de memória ideal de forma semelhante a .

```
void* PASCAL operator new(size_t nSize);
void* PASCAL operator new(size_t, void* p);

void* PASCAL operator new(
    size_t nSize,
    LPCSTR lpszFileName,
    int nLine);
```

### <a name="remarks"></a>Comentários

Na versão Debug, o **operador novo** participa de um esquema de monitoramento de alocação projetado para detectar vazamentos de memória.

Se você usar a linha de código

[!code-cpp[NVC_MFCCObjectSample#14](../../mfc/codesnippet/cpp/cobject-class_7.cpp)]

antes de qualquer uma de suas implementações em um . Arquivo CPP, em seguida, a segunda versão do **novo** será usado, armazenando o nome do arquivo e o número de linha no bloco alocado para relatórios posteriores. Você não precisa se preocupar em fornecer os parâmetros extras; uma macro cuida disso para você.

Mesmo que você não use DEBUG_NEW no modo Debug, você ainda terá detecção de vazamento, mas sem o relatório de número de linha de arquivo de origem descrito acima.

> [!NOTE]
> Se você substituir este operador, você também deve substituir **a exclusão**. Não use a `_new_handler` função de biblioteca padrão.

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada nos exemplos.

[!code-cpp[NVC_MFCCObjectSample#16](../../mfc/codesnippet/cpp/cobject-class_9.h)]

## <a name="cobjectserialize"></a><a name="serialize"></a>CObject::Serialize

Lê ou escreve este objeto de ou para um arquivo.

```
virtual void Serialize(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Um `CArchive` objeto para serializar para ou de.

### <a name="remarks"></a>Comentários

Você deve `Serialize` substituir para cada classe que você pretende serializar. Os substituídos `Serialize` devem primeiro `Serialize` chamar a função de sua classe base.

Você também deve usar a [macro DECLARE_SERIAL](run-time-object-model-services.md#declare_serial) em sua declaração de classe, e você deve usar a [macro IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) na implementação.

Use [CArchive::IsLoading](../../mfc/reference/carchive-class.md#isloading) ou [CArchive::IsStoring](../../mfc/reference/carchive-class.md#isstoring) para determinar se o arquivo está carregando ou armazenando.

`Serialize`é chamado por [CArchive::ReadObject](../../mfc/reference/carchive-class.md#readobject) e [CArchive::WriteObject](../../mfc/reference/carchive-class.md#writeobject). Essas funções estão `CArchive` associadas ** < **ao operador de **>>** inserção ( ) e operador de extração ( ).

Para exemplos de serialização, consulte o artigo [Serialização: Serializing a Object](../../mfc/serialization-serializing-an-object.md).

### <a name="example"></a>Exemplo

Consulte [CObList::CObList](../../mfc/reference/coblist-class.md#coblist) para obter `CAge` uma listagem `CObject` da classe usada em todos os exemplos.

[!code-cpp[NVC_MFCCObjectSample#13](../../mfc/codesnippet/cpp/cobject-class_10.cpp)]

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
