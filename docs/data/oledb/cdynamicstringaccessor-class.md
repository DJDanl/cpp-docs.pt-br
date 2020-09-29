---
title: Classe CDynamicStringAccessor
ms.date: 11/04/2016
f1_keywords:
- CDynamicStringAccessor
- CDynamicStringAccessor.GetString
- CDynamicStringAccessor::GetString
- CDynamicStringAccessor::SetString
- CDynamicStringAccessor.SetString
helpviewer_keywords:
- CDynamicStringAccessor class
- GetString method
- SetString method
ms.assetid: 138dc4de-c7c3-478c-863e-431e48249027
ms.openlocfilehash: 891c80a7c21fd046fba393b494ed6d84f731db6f
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91498662"
---
# <a name="cdynamicstringaccessor-class"></a>Classe CDynamicStringAccessor

Permite que você acesse uma fonte de dados quando não tem nenhum conhecimento do esquema de banco (a estrutura subjacente do banco de dado).

## <a name="syntax"></a>Sintaxe

```cpp
template< typename BaseType, DBTYPEENUM OleDbType >
class CDynamicStringAccessorT : public CDynamicAccessor
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

| Nome | Descrição |
|-|-|
|[GetString](#getstring)|Recupera os dados da coluna especificada como uma cadeia de caracteres.|
|[SetString](#setstring)|Define os dados da coluna especificada como uma cadeia de caracteres.|

## <a name="remarks"></a>Comentários

Embora o [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) solicite dados no formato nativo relatado pelo provedor, `CDynamicStringAccessor` o solicita que o provedor busque todos os dados acessados do armazenamento de dados como dados de cadeia de caracteres. Isso é especialmente útil para tarefas simples que não exigem o cálculo de valores no armazenamento de dados, como exibir ou imprimir o conteúdo do armazenamento de dados.

O tipo nativo de dados de coluna no repositório de dados não importa; desde que o provedor possa dar suporte à conversão de dados, ele fornecerá os dados no formato de cadeia de caracteres. Se o provedor não oferecer suporte à conversão do tipo de dados nativo em uma cadeia de caracteres (o que não é comum), a chamada solicitante retornará o valor de êxito DB_S_ERRORSOCCURED e o status da coluna correspondente indicará um problema de conversão com DBSTATUS_E_CANTCONVERTVALUE.

Use `CDynamicStringAccessor` métodos para obter informações de coluna. Use essas informações de coluna para criar um acessador dinamicamente em tempo de execução.

As informações de coluna são armazenadas em um buffer criado e gerenciado por essa classe. Obtenha dados do buffer usando [GetString](#getstring)ou armazene-os no buffer usando [SetString](#setstring).

Para obter uma discussão e exemplos de como usar as classes de acessador dinâmico, consulte [usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).

## <a name="cdynamicstringaccessorgetstring"></a><a name="getstring"></a> CDynamicStringAccessor:: GetString

Recupera os dados da coluna especificada como uma cadeia de caracteres.

### <a name="syntax"></a>Sintaxe

```cpp
BaseType* GetString(DBORDINAL nColumn) const throw();

BaseType* GetString(const CHAR* pColumnName) const throw();

BaseType* GetString(const WCHAR* pColumnName) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. Um valor de 0 se refere à coluna de indicador, se houver.

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

### <a name="return-value"></a>Valor Retornado

Um ponteiro para o valor da cadeia de caracteres recuperado da coluna especificada. O valor é do tipo `BaseType` , que será **Char** ou **WCHAR** , dependendo se _UNICODE é definido ou não. Retornará NULL se a coluna especificada não for encontrada.

### <a name="remarks"></a>Comentários

O segundo formulário de substituição usa o nome da coluna como uma cadeia de caracteres ANSI. O terceiro formulário de substituição usa o nome da coluna como uma cadeia de caracteres Unicode.

## <a name="cdynamicstringaccessorsetstring"></a><a name="setstring"></a> CDynamicStringAccessor:: SetString

Define os dados da coluna especificada como uma cadeia de caracteres.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT SetString(DBORDINAL nColumn,
   BaseType* data) throw();

HRESULT SetString(const CHAR* pColumnName,
   BaseType* data) throw();

HRESULT SetString(const WCHAR* pColumnName,
   BaseType* data) throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
no O número da coluna. Os números de coluna começam com 1. O valor especial de 0 se refere à coluna de indicador, se houver.

*pColumnName*<br/>
no Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*data*<br/>
no Um ponteiro para os dados de cadeia de caracteres a serem gravados na coluna especificada.

### <a name="return-value"></a>Valor Retornado

Um ponteiro para o valor da cadeia de caracteres para o qual definir a coluna especificada. O valor é do tipo `BaseType` , que será **Char** ou **WCHAR** , dependendo se _UNICODE é definido ou não.

### <a name="remarks"></a>Comentários

O segundo formulário de substituição usa o nome da coluna como uma cadeia de caracteres ANSI e o terceiro formulário de substituição usa o nome da coluna como uma cadeia de caracteres Unicode.

Se _SECURE_ATL for definido para ter um valor diferente de zero, uma falha de asserção de tempo de execução será gerada se a cadeia de caracteres de *dados* de entrada for maior do que o comprimento máximo permitido da coluna de dados referenciada. Caso contrário, a cadeia de caracteres de entrada será truncada se for maior do que o comprimento máximo permitido.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)<br/>
[Classe CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)<br/>
[Classe CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)
