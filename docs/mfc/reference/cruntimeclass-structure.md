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
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57274291"
---
# <a name="cruntimeclass-structure"></a>Estrutura CRuntimeClass

Cada classe derivada de `CObject` está associado com um `CRuntimeClass` estrutura que você pode usar para obter informações sobre um objeto ou sua classe base em tempo de execução.

## <a name="syntax"></a>Sintaxe

```
struct CRuntimeClass
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRuntimeClass::CreateObject](#createobject)|Cria um objeto durante o tempo de execução.|
|[CRuntimeClass::FromName](#fromname)|Cria um objeto durante o tempo de execução usando o nome da classe familiar.|
|[CRuntimeClass::IsDerivedFrom](#isderivedfrom)|Determina se a classe é derivada da classe especificada.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRuntimeClass::m_lpszClassName](#m_lpszclassname)|O nome da classe.|
|[CRuntimeClass::m_nObjectSize](#m_nobjectsize)|O tamanho do objeto em bytes.|
|[CRuntimeClass::m_pBaseClass](#m_pbaseclass)|Um ponteiro para o `CRuntimeClass` estrutura da classe base.|
|[CRuntimeClass::m_pfnCreateObject](#m_pfncreateobject)|Um ponteiro para a função que cria dinamicamente o objeto.|
|[CRuntimeClass::m_pfnGetBaseClass](#m_pfngetbaseclass)|Retorna o `CRuntimeClass` estrutura (somente disponível quando dinamicamente vinculado).|
|[CRuntimeClass::m_wSchema](#m_wschema)|O número de esquema da classe.|

## <a name="remarks"></a>Comentários

`CRuntimeClass` é uma estrutura e, portanto, não tem uma classe base.

A capacidade de determinar a classe de um objeto em tempo de execução é útil quando a verificação dos argumentos da função de tipo adicional é necessária, ou quando você deve escrever o código de finalidade especial com base na classe de um objeto. Não há suporte para informações de classe de tempo de execução diretamente pela linguagem C++.

`CRuntimeClass` Fornece informações sobre o objeto relacionado do C++, como um ponteiro para o `CRuntimeClass` da classe base e o nome da classe ASCII da classe relacionada. Essa estrutura também implementa várias funções que podem ser usadas para criar dinamicamente objetos, especificando o tipo de objeto usando um nome familiar e determinar se a classe relacionada é derivada de uma classe específica.

Para obter mais informações sobre como usar `CRuntimeClass`, consulte o artigo [acessando informações de classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CRuntimeClass`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** AFX. h

##  <a name="createobject"></a>  CRuntimeClass::CreateObject

Chame essa função para criar dinamicamente a classe especificada durante o tempo de execução.

```
CObject* CreateObject();

static CObject* PASCAL CreateObject(LPCSTR lpszClassName);

static CObject* PASCAL CreateObject(LPCWSTR lpszClassName);
```

### <a name="parameters"></a>Parâmetros

*lpszClassName*<br/>
O nome familiar da classe a ser criado.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o objeto recém-criado ou nulo se o nome de classe não for encontrado ou não há memória suficiente para criar o objeto.

### <a name="remarks"></a>Comentários

As classes derivadas de `CObject` pode dar suporte a criação dinâmica, que é a capacidade de criar um objeto de uma classe especificada em tempo de execução. Documento, exibição e classes de quadro, por exemplo, devem dar suporte a criação dinâmica. Para obter mais informações sobre a criação dinâmica e o `CreateObject` membro, consulte [classe CObject](../../mfc/using-cobject.md) e [classe CObject: Especificando níveis de funcionalidade](../../mfc/specifying-levels-of-functionality.md).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="fromname"></a>  CRuntimeClass::FromName

Chame essa função para recuperar o `CRuntimeClass` estrutura associada com o nome familiar.

```
static CRuntimeClass* PASCAL FromName(LPCSTR lpszClassName);

static CRuntimeClass* PASCAL FromName(LPCWSTR lpszClassName);
```

### <a name="parameters"></a>Parâmetros

*lpszClassName*<br/>
O nome conhecido de uma classe derivada de `CObject`.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para um `CRuntimeClass` objeto, correspondente ao nome do conforme transmitido *lpszClassName*. A função retornará NULL se nenhum nome de classe correspondente foi encontrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#17](../../mfc/codesnippet/cpp/cruntimeclass-structure_1.cpp)]

##  <a name="isderivedfrom"></a>  CRuntimeClass::IsDerivedFrom

Chame essa função para determinar se a classe chamada deriva da classe especificada na *pBaseClass* parâmetro.

```
BOOL IsDerivedFrom(const CRuntimeClass* pBaseClass) const;
```

### <a name="parameters"></a>Parâmetros

*pBaseClass*<br/>
O nome conhecido de uma classe derivada de `CObject`.

### <a name="return-value"></a>Valor de retorno

TRUE se a chamada de classe `IsDerivedFrom` é derivado de base da classe cuja `CRuntimeClass` estrutura é fornecida como um parâmetro; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

A relação é determinada pelo "caminhada" da classe do membro, a cadeia de classes derivadas até a parte superior. Essa função só retorna FALSE se nenhuma correspondência for encontrada para a classe base.

> [!NOTE]
>  Para usar o `CRuntimeClass` estrutura, você deve incluir a macro IMPLEMENT_DYNAMIC, IMPLEMENT_DYNCREATE ou IMPLEMENT_SERIAL na implementação da classe para o qual você deseja recuperar informações de objeto de tempo de execução.

Para obter mais informações sobre como usar `CRuntimeClass`, consulte o artigo [classe CObject: Acessando informações da classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#18](../../mfc/codesnippet/cpp/cruntimeclass-structure_2.cpp)]

##  <a name="m_lpszclassname"></a>  CRuntimeClass::m_lpszClassName

Uma cadeia terminada em nulo que contém o nome de classe de ASCII.

### <a name="remarks"></a>Comentários

Esse nome pode ser usado para criar uma instância da classe usando o `FromName` função de membro.

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_nobjectsize"></a>  CRuntimeClass::m_nObjectSize

O tamanho do objeto, em bytes.

### <a name="remarks"></a>Comentários

Se o objeto tiver membros de dados que apontam para a memória alocada, o tamanho do que a memória não está incluído.

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_pbaseclass"></a>  CRuntimeClass::m_pBaseClass

Se seu aplicativo se vincula estaticamente ao MFC, este membro de dados contém um ponteiro para o `CRuntimeClass` estrutura da classe base.

### <a name="remarks"></a>Comentários

Se seu aplicativo se vincula dinamicamente com a biblioteca MFC, consulte [m_pfnGetBaseClass](#m_pfngetbaseclass).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_pfncreateobject"></a>  CRuntimeClass::m_pfnCreateObject

Um ponteiro de função para o construtor padrão que cria um objeto de sua classe.

### <a name="remarks"></a>Comentários

Esse ponteiro só será válido se a classe dá suporte à criação dinâmica; Caso contrário, a função retornará NULL.

##  <a name="m_pfngetbaseclass"></a>  CRuntimeClass::m_pfnGetBaseClass

Se seu aplicativo usa a biblioteca do MFC como uma DLL compartilhada, este membro de dados aponta para uma função que retorna o `CRuntimeClass` estrutura da classe base.

### <a name="remarks"></a>Comentários

Se seu aplicativo se vincula estaticamente para a biblioteca MFC, consulte [m_pBaseClass](#m_pbaseclass).

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsDerivedFrom](#isderivedfrom).

##  <a name="m_wschema"></a>  CRuntimeClass::m_wSchema

O número de esquema (-1 para classes não serializáveis).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre números de esquema, consulte o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro.

### <a name="example"></a>Exemplo

  Veja o exemplo de [IsDerivedFrom](#isderivedfrom).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CObject::GetRuntimeClass](../../mfc/reference/cobject-class.md#getruntimeclass)<br/>
[CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof)<br/>
[RUNTIME_CLASS](run-time-object-model-services.md#runtime_class)<br/>
[IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic)<br/>
[IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate)<br/>
[IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial)
