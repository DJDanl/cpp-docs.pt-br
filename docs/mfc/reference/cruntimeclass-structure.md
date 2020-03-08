---
title: Estrutura CRuntimeClass
ms.date: 11/04/2016
f1_keywords:
- CRuntimeClass
helpviewer_keywords:
- CRuntimeClass structure [MFC]
- dynamic class information [MFC]
- runtime [MFC], class information
- run-time class [MFC], CRuntimeClass structure
ms.assetid: de62b6ef-90d4-420f-8c70-f58b36976a2b
ms.openlocfilehash: 92979a10c18d9759e0ecc9f0785e56a97c0f0642
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78874020"
---
# <a name="cruntimeclass-structure"></a>Estrutura CRuntimeClass

Cada classe derivada de `CObject` é associada a uma estrutura de `CRuntimeClass` que você pode usar para obter informações sobre um objeto ou sua classe base em tempo de execução.

## <a name="syntax"></a>Sintaxe

```
struct CRuntimeClass
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CRuntimeClass:: CreateObject](#createobject)|Cria um objeto durante o tempo de execução.|
|[CRuntimeClass::FromName](#fromname)|Cria um objeto durante o tempo de execução usando o conhecido nome de classe.|
|[CRuntimeClass::IsDerivedFrom](#isderivedfrom)|Determina se a classe é derivada da classe especificada.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CRuntimeClass:: m_lpszClassName](#m_lpszclassname)|O nome da classe.|
|[CRuntimeClass:: m_nObjectSize](#m_nobjectsize)|O tamanho do objeto em bytes.|
|[CRuntimeClass:: m_pBaseClass](#m_pbaseclass)|Um ponteiro para a estrutura de `CRuntimeClass` da classe base.|
|[CRuntimeClass:: m_pfnCreateObject](#m_pfncreateobject)|Um ponteiro para a função que cria dinamicamente o objeto.|
|[CRuntimeClass:: m_pfnGetBaseClass](#m_pfngetbaseclass)|Retorna a estrutura de `CRuntimeClass` (disponível somente quando vinculada dinamicamente).|
|[CRuntimeClass:: m_wSchema](#m_wschema)|O número de esquema da classe.|

## <a name="remarks"></a>Comentários

`CRuntimeClass` é uma estrutura e, portanto, não tem uma classe base.

A capacidade de determinar a classe de um objeto em tempo de execução é útil quando a verificação de tipo extra de argumentos de função é necessária ou quando você deve escrever código de finalidade especial com base na classe de um objeto. Não há suporte para informações de C++ classe em tempo de execução diretamente pelo idioma.

`CRuntimeClass` fornece informações sobre o objeto C++ relacionado, como um ponteiro para a `CRuntimeClass` da classe base e o nome da classe ASCII da classe relacionada. Essa estrutura também implementa várias funções que podem ser usadas para criar objetos dinamicamente, especificando o tipo de objeto usando um nome familiar e determinando se a classe relacionada é derivada de uma classe específica.

Para obter mais informações sobre como usar `CRuntimeClass`, consulte o artigo [Acessando informações de classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CRuntimeClass`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** AFX. h

##  <a name="createobject"></a>CRuntimeClass:: CreateObject

Chame essa função para criar dinamicamente a classe especificada durante o tempo de execução.

```
CObject* CreateObject();

static CObject* PASCAL CreateObject(LPCSTR lpszClassName);

static CObject* PASCAL CreateObject(LPCWSTR lpszClassName);
```

### <a name="parameters"></a>Parâmetros

*lpszClassName*<br/>
O nome familiar da classe a ser criada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto recém-criado ou NULL se o nome da classe não for encontrado ou se não houver memória suficiente para criar o objeto.

### <a name="remarks"></a>Comentários

Classes derivadas de `CObject` podem oferecer suporte à criação dinâmica, que é a capacidade de criar um objeto de uma classe especificada em tempo de execução. As classes Document, View e frame, por exemplo, devem oferecer suporte à criação dinâmica. Para obter mais informações sobre a criação dinâmica e o membro de `CreateObject`, consulte [classe CObject](../../mfc/using-cobject.md) e [classe CObject: especificando níveis de funcionalidade](../../mfc/specifying-levels-of-functionality.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="fromname"></a>CRuntimeClass::FromName

Chame essa função para recuperar a estrutura de `CRuntimeClass` associada ao nome familiar.

```
static CRuntimeClass* PASCAL FromName(LPCSTR lpszClassName);

static CRuntimeClass* PASCAL FromName(LPCWSTR lpszClassName);
```

### <a name="parameters"></a>Parâmetros

*lpszClassName*<br/>
O nome familiar de uma classe derivada de `CObject`.

### <a name="return-value"></a>Valor retornado

Um ponteiro para um objeto `CRuntimeClass`, correspondente ao nome passado em *lpszClassName*. A função retornará NULL se nenhum nome de classe correspondente for encontrado.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCCObjectSample#17](../../mfc/codesnippet/cpp/cruntimeclass-structure_1.cpp)]

##  <a name="isderivedfrom"></a>CRuntimeClass::IsDerivedFrom

Chame essa função para determinar se a classe de chamada é derivada da classe especificada no parâmetro *pBaseClass* .

```
BOOL IsDerivedFrom(const CRuntimeClass* pBaseClass) const;
```

### <a name="parameters"></a>Parâmetros

*pBaseClass*<br/>
O nome familiar de uma classe derivada de `CObject`.

### <a name="return-value"></a>Valor retornado

TRUE se a classe que está chamando `IsDerivedFrom` for derivada da classe base cuja estrutura de `CRuntimeClass` é fornecida como um parâmetro; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A relação é determinada pela "movimentação" da classe do membro a cadeia de classes derivadas até o topo. Essa função retornará FALSE somente se nenhuma correspondência for encontrada para a classe base.

> [!NOTE]
>  Para usar a estrutura de `CRuntimeClass`, você deve incluir a macro IMPLEMENT_DYNAMIC, IMPLEMENT_DYNCREATE ou IMPLEMENT_SERIAL na implementação da classe para a qual deseja recuperar informações de objeto de tempo de execução.

Para obter mais informações sobre como usar `CRuntimeClass`, consulte o artigo [classe CObject: Acessando informações de classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_MFCCObjectSample#18](../../mfc/codesnippet/cpp/cruntimeclass-structure_2.cpp)]

##  <a name="m_lpszclassname"></a>CRuntimeClass:: m_lpszClassName

Uma cadeia de caracteres terminada em nulo que contém o nome da classe ASCII.

### <a name="remarks"></a>Comentários

Esse nome pode ser usado para criar uma instância da classe usando a função de membro `FromName`.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_nobjectsize"></a>CRuntimeClass:: m_nObjectSize

O tamanho do objeto, em bytes.

### <a name="remarks"></a>Comentários

Se o objeto tiver membros de dados que apontam para a memória alocada, o tamanho dessa memória não será incluído.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_pbaseclass"></a>CRuntimeClass:: m_pBaseClass

Se seu aplicativo se vincula estaticamente ao MFC, esse membro de dados contém um ponteiro para a estrutura de `CRuntimeClass` da classe base.

### <a name="remarks"></a>Comentários

Se o seu aplicativo se vincula dinamicamente à biblioteca do MFC, consulte [m_pfnGetBaseClass](#m_pfngetbaseclass).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_pfncreateobject"></a>CRuntimeClass:: m_pfnCreateObject

Um ponteiro de função para o construtor padrão que cria um objeto de sua classe.

### <a name="remarks"></a>Comentários

Esse ponteiro só será válido se a classe oferecer suporte à criação dinâmica; caso contrário, a função retornará NULL.

##  <a name="m_pfngetbaseclass"></a>CRuntimeClass:: m_pfnGetBaseClass

Se seu aplicativo usar a biblioteca do MFC como uma DLL compartilhada, esse membro de dados apontará para uma função que retorna a estrutura de `CRuntimeClass` da classe base.

### <a name="remarks"></a>Comentários

Se seu aplicativo se vincula estaticamente à biblioteca do MFC, consulte [m_pBaseClass](#m_pbaseclass).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_wschema"></a>CRuntimeClass:: m_wSchema

O número do esquema (-1 para classes não serializáveis).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre os números de esquema, consulte a macro [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) .

### <a name="example"></a>{1&gt;Exemplo&lt;1}

  Consulte o exemplo de [IsDerivedFrom](#isderivedfrom).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CObject::GetRuntimeClass](../../mfc/reference/cobject-class.md#getruntimeclass)<br/>
[CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof)<br/>
[RUNTIME_CLASS](run-time-object-model-services.md#runtime_class)<br/>
[IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic)<br/>
[IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate)<br/>
[IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial)
