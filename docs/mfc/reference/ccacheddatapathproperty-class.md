---
title: Classe CCachedDataPathProperty
ms.date: 11/04/2016
f1_keywords:
- CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty::CCachedDataPathProperty
- AFXCTL/CCachedDataPathProperty::m_Cache
helpviewer_keywords:
- CCachedDataPathProperty [MFC], CCachedDataPathProperty
- CCachedDataPathProperty [MFC], m_Cache
ms.assetid: 0d81356b-4fe5-43f6-aed2-2eb5a5485706
ms.openlocfilehash: ebab34433f23b119e3444b3eaa8b0ad6313555af
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81352360"
---
# <a name="ccacheddatapathproperty-class"></a>Classe CCachedDataPathProperty

Implementa uma propriedade de controle OLE transferida assíncronamente e armazenada em cache em um arquivo de memória.

## <a name="syntax"></a>Sintaxe

```
class CCachedDataPathProperty : public CDataPathProperty
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CCachedDataPathPropriedade:CCachedDataPathProperty](#ccacheddatapathproperty)|Constrói um objeto `CCachedDataPathProperty`.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCachedDataPathPropriedade::m_Cache](#m_cache)|`CMemFile`objeto em que fazer cache de dados.|

## <a name="remarks"></a>Comentários

Um arquivo de memória é armazenado em RAM em vez de em disco e é útil para transferências temporárias rápidas.

Juntamente `CAysncMonikerFile` `CDataPathProperty`com `CCachedDataPathProperty` e , fornece funcionalidade para o uso de apelidos assíncronos em controles OLE. Com `CCachedDataPathProperty` objetos, você é capaz de transferir dados assíncronamente de uma `m_Cache` URL ou fonte de arquivo e armazená-los em um arquivo de memória através da variável pública. Todos os dados são armazenados no arquivo de memória, e não há necessidade de substituir [o OnDataAvailable,](../../mfc/reference/casyncmonikerfile-class.md#ondataavailable) a menos que você queira assistir a notificações e responder. Por exemplo, se você está transferindo um grande . Arquivo GIF e quer notificar o seu controle de que mais `OnDataAvailable` dados chegaram e ele deve se redesenhar, anular para fazer a notificação.

A `CCachedDataPathProperty` classe é `CDataPathProperty`derivada de .

Para obter mais informações sobre como usar apelidos assíncronos e controles ActiveX em aplicativos da Internet, consulte os seguintes tópicos:

- [Primeiros passos da Internet: Controles ActiveX](../../mfc/activex-controls-on-the-internet.md)

- [Primeiros Passos da Internet: Apelidos Assíncronos](../../mfc/asynchronous-monikers-on-the-internet.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Cfile](../../mfc/reference/cfile-class.md)

[Colestreamfile](../../mfc/reference/colestreamfile-class.md)

[Cmonikerfile](../../mfc/reference/cmonikerfile-class.md)

[Casyncmonikerfile](../../mfc/reference/casyncmonikerfile-class.md)

[Cdatapathproperty](../../mfc/reference/cdatapathproperty-class.md)

`CCachedDataPathProperty`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl.h

## <a name="ccacheddatapathpropertyccacheddatapathproperty"></a><a name="ccacheddatapathproperty"></a>CCachedDataPathPropriedade:CCachedDataPathProperty

Constrói um objeto `CCachedDataPathProperty`.

```
CCachedDataPathProperty(COleControl* pControl = NULL);

CCachedDataPathProperty(
    LPCTSTR lpszPath,
    COleControl* pControl = NULL);
```

### <a name="parameters"></a>Parâmetros

*pControl*<br/>
Um ponteiro para o objeto de controle `CCachedDataPathProperty` ActiveX a ser associado a este objeto.

*lpszPath*<br/>
O caminho, que pode ser absoluto ou relativo, foi usado para criar um apelido assíncrono que faz referência à localização absoluta real da propriedade. `CCachedDataPathProperty`usa URLs, não nomes de arquivos. Se você `CCachedDataPathProperty` quiser um objeto para um arquivo, prepare-se file:// para o caminho.

### <a name="remarks"></a>Comentários

O `COleControl` objeto apontado pelo *pControl* é usado pelo [Open](../../mfc/reference/cdatapathproperty-class.md#open) e recuperado por classes derivadas. Se *o pControl* for NULL, o controle usado deve `Open` ser definido com [SetControl](../../mfc/reference/cdatapathproperty-class.md#setcontrol). Se *o lpszPath* for NULL, você `Open` pode passar no caminho ou configurá-lo com [SetPath](../../mfc/reference/cdatapathproperty-class.md#setpath).

## <a name="ccacheddatapathpropertym_cache"></a><a name="m_cache"></a>CCachedDataPathPropriedade::m_Cache

Contém o nome de classe do arquivo de memória no qual os dados são armazenados em cache.

```
CMemFile m_Cache;
```

### <a name="remarks"></a>Comentários

Um arquivo de memória é armazenado na RAM em vez de em disco.

## <a name="see-also"></a>Confira também

[Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CDataPathProperty](../../mfc/reference/cdatapathproperty-class.md)
