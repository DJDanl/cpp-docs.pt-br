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
ms.openlocfilehash: a58b9c97d5683423a0f81f6b5424f19f987943bf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318558"
---
# <a name="cruntimeclass-structure"></a>Estrutura CRuntimeClass

Cada classe derivada `CObject` está `CRuntimeClass` associada a uma estrutura que você pode usar para obter informações sobre um objeto ou sua classe base em tempo de execução.

## <a name="syntax"></a>Sintaxe

```
struct CRuntimeClass
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CRuntimeClasse::CriarObjeto](#createobject)|Cria um objeto durante o tempo de execução.|
|[CRuntimeClasse::Desnomear](#fromname)|Cria um objeto durante o tempo de execução usando o nome de classe familiar.|
|[CRuntimeClass::IsDerivedFrom](#isderivedfrom)|Determina se a classe é derivada da classe especificada.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CRuntimeClass::m_lpszClassName](#m_lpszclassname)|O nome da classe.|
|[CRuntimeClass::m_nObjectSize](#m_nobjectsize)|O tamanho do objeto em bytes.|
|[CRuntimeClass::m_pBaseClass](#m_pbaseclass)|Um ponteiro `CRuntimeClass` para a estrutura da classe base.|
|[CRuntimeClass::m_pfnCreateObject](#m_pfncreateobject)|Um ponteiro para a função que dinamicamente cria o objeto.|
|[CRuntimeClass::m_pfnGetBaseClass](#m_pfngetbaseclass)|Retorna `CRuntimeClass` a estrutura (disponível apenas quando dinamicamente ligada).|
|[CRuntimeClass::m_wSchema](#m_wschema)|O número do esquema da classe.|

## <a name="remarks"></a>Comentários

`CRuntimeClass`é uma estrutura e, portanto, não tem uma classe base.

A capacidade de determinar a classe de um objeto no tempo de execução é útil quando a verificação de tipo extra dos argumentos de função é necessária ou quando você deve escrever código de propósito especial com base na classe de um objeto. As informações da classe de tempo de execução não são suportadas diretamente pelo idioma C++.

`CRuntimeClass`fornece informações sobre o objeto C++ relacionado, `CRuntimeClass` como um ponteiro para a classe base e o nome da classe ASCII da classe relacionada. Essa estrutura também implementa várias funções que podem ser usadas para criar objetos dinamicamente, especificando o tipo de objeto usando um nome familiar e determinando se a classe relacionada é derivada de uma classe específica.

Para obter mais `CRuntimeClass`informações sobre como usar, consulte o artigo [Acessando informações de classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`CRuntimeClass`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afx.h

## <a name="cruntimeclasscreateobject"></a><a name="createobject"></a>CRuntimeClasse::CriarObjeto

Chame esta função para criar dinamicamente a classe especificada durante o tempo de execução.

```
CObject* CreateObject();

static CObject* PASCAL CreateObject(LPCSTR lpszClassName);

static CObject* PASCAL CreateObject(LPCWSTR lpszClassName);
```

### <a name="parameters"></a>Parâmetros

*Lpszclassname*<br/>
O nome familiar da classe a ser criada.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto recém-criado, ou NULL se o nome da classe não for encontrado ou houver memória insuficiente para criar o objeto.

### <a name="remarks"></a>Comentários

Classes derivadas `CObject` podem suportar a criação dinâmica, que é a capacidade de criar um objeto de uma classe especificada em tempo de execução. As classes de documento, visualização e quadro, por exemplo, devem suportar a criação dinâmica. Para obter mais informações `CreateObject` sobre criação dinâmica e o membro, consulte [Classe CObject](../../mfc/using-cobject.md) e [Classe CObject: Especificando níveis de funcionalidade](../../mfc/specifying-levels-of-functionality.md).

### <a name="example"></a>Exemplo

  Veja o exemplo [de IsDerivedFrom](#isderivedfrom).

## <a name="cruntimeclassfromname"></a><a name="fromname"></a>CRuntimeClasse::Desnomear

Chame esta função `CRuntimeClass` para recuperar a estrutura associada ao nome familiar.

```
static CRuntimeClass* PASCAL FromName(LPCSTR lpszClassName);

static CRuntimeClass* PASCAL FromName(LPCWSTR lpszClassName);
```

### <a name="parameters"></a>Parâmetros

*Lpszclassname*<br/>
O nome familiar de uma `CObject`classe derivada de .

### <a name="return-value"></a>Valor retornado

Um ponteiro `CRuntimeClass` para um objeto, correspondente ao nome aprovado em *lpszClassName*. A função retorna NULL se nenhum nome de classe correspondente foi encontrado.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#17](../../mfc/codesnippet/cpp/cruntimeclass-structure_1.cpp)]

## <a name="cruntimeclassisderivedfrom"></a><a name="isderivedfrom"></a>CRuntimeClass::IsDerivedFrom

Chame esta função para determinar se a classe de chamada é derivada da classe especificada no parâmetro *pBaseClass.*

```
BOOL IsDerivedFrom(const CRuntimeClass* pBaseClass) const;
```

### <a name="parameters"></a>Parâmetros

*pBaseClass*<br/>
O nome familiar de uma `CObject`classe derivada de .

### <a name="return-value"></a>Valor retornado

VERDADE se a `IsDerivedFrom` chamada de classe é `CRuntimeClass` derivada da classe base cuja estrutura é dada como parâmetro; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

A relação é determinada por "caminhar" da classe do membro até a cadeia de classes derivadas até o topo. Esta função só retorna FALSA se não for encontrada correspondência para a classe base.

> [!NOTE]
> Para usar `CRuntimeClass` a estrutura, você deve incluir a IMPLEMENT_DYNAMIC, IMPLEMENT_DYNCREATE ou IMPLEMENT_SERIAL macro na implementação da classe para a qual você deseja recuperar informações de objeto em tempo de execução.

Para obter mais `CRuntimeClass`informações sobre o uso, consulte o artigo [CObject Class: Acessando informações de classe de tempo de execução](../../mfc/accessing-run-time-class-information.md).

### <a name="example"></a>Exemplo

[!code-cpp[NVC_MFCCObjectSample#18](../../mfc/codesnippet/cpp/cruntimeclass-structure_2.cpp)]

## <a name="cruntimeclassm_lpszclassname"></a><a name="m_lpszclassname"></a>CRuntimeClass::m_lpszClassName

Uma seqüência de terminadas nula contendo o nome da classe ASCII.

### <a name="remarks"></a>Comentários

Este nome pode ser usado para criar `FromName` uma instância da classe usando a função membro.

### <a name="example"></a>Exemplo

  Veja o exemplo [de IsDerivedFrom](#isderivedfrom).

## <a name="cruntimeclassm_nobjectsize"></a><a name="m_nobjectsize"></a>CRuntimeClass::m_nObjectSize

O tamanho do objeto, em bytes.

### <a name="remarks"></a>Comentários

Se o objeto tiver membros de dados que apontam para a memória alocada, o tamanho dessa memória não será incluído.

### <a name="example"></a>Exemplo

  Veja o exemplo [de IsDerivedFrom](#isderivedfrom).

## <a name="cruntimeclassm_pbaseclass"></a><a name="m_pbaseclass"></a>CRuntimeClass::m_pBaseClass

Se o aplicativo se vincula estática mente ao `CRuntimeClass` MFC, este membro de dados contém um ponteiro para a estrutura da classe base.

### <a name="remarks"></a>Comentários

Se o aplicativo se vincula dinamicamente à biblioteca Do MFC, consulte [m_pfnGetBaseClass](#m_pfngetbaseclass).

### <a name="example"></a>Exemplo

  Veja o exemplo [de IsDerivedFrom](#isderivedfrom).

## <a name="cruntimeclassm_pfncreateobject"></a><a name="m_pfncreateobject"></a>CRuntimeClass::m_pfnCreateObject

Um ponteiro de função para o construtor padrão que cria um objeto da sua classe.

### <a name="remarks"></a>Comentários

Este ponteiro só é válido se a classe suportar a criação dinâmica; caso contrário, a função retorna NULL.

## <a name="cruntimeclassm_pfngetbaseclass"></a><a name="m_pfngetbaseclass"></a>CRuntimeClass::m_pfnGetBaseClass

Se o aplicativo usar a biblioteca MFC como um DLL compartilhado, `CRuntimeClass` esse membro de dados aponta para uma função que retorna a estrutura da classe base.

### <a name="remarks"></a>Comentários

Se o aplicativo se vincula estática à biblioteca do MFC, consulte [m_pBaseClass](#m_pbaseclass).

### <a name="example"></a>Exemplo

  Veja o exemplo [de IsDerivedFrom](#isderivedfrom).

## <a name="cruntimeclassm_wschema"></a><a name="m_wschema"></a>CRuntimeClass::m_wSchema

O número do esquema (-1 para classes não seriais).

### <a name="remarks"></a>Comentários

Para obter mais informações sobre números de esquemas, consulte a [macro IMPLEMENT_SERIAL.](run-time-object-model-services.md#implement_serial)

### <a name="example"></a>Exemplo

  Veja o exemplo [de IsDerivedFrom](#isderivedfrom).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[CObject::GetRuntimeClass](../../mfc/reference/cobject-class.md#getruntimeclass)<br/>
[CObject::IsKindOf](../../mfc/reference/cobject-class.md#iskindof)<br/>
[Runtime_class](run-time-object-model-services.md#runtime_class)<br/>
[IMPLEMENT_DYNAMIC](run-time-object-model-services.md#implement_dynamic)<br/>
[IMPLEMENT_DYNCREATE](run-time-object-model-services.md#implement_dyncreate)<br/>
[IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial)
