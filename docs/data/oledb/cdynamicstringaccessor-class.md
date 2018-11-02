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
ms.openlocfilehash: dff36dfb2b898c6a4df65492e2d9386c748f049b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50534609"
---
# <a name="cdynamicstringaccessor-class"></a>Classe CDynamicStringAccessor

Permite que você acesse uma fonte de dados quando você não tem nenhum conhecimento sobre o esquema de banco de dados (estrutura de base do banco de dados).

## <a name="syntax"></a>Sintaxe

```cpp
template< typename BaseType, DBTYPEENUM OleDbType >
class CDynamicStringAccessorT : public CDynamicAccessor
```

## <a name="requirements"></a>Requisitos

**Cabeçalho**: atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[GetString](#getstring)|Recupera os dados da coluna especificada como uma cadeia de caracteres.|
|[SetString](#setstring)|Define os dados da coluna especificada como uma cadeia de caracteres.|

## <a name="remarks"></a>Comentários

Embora [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) solicita dados no formato nativo relatado pelo provedor, `CDynamicStringAccessor` solicita que o provedor de buscar todos os dados acessados do armazenamento de dados como dados de cadeia de caracteres. Isso é especialmente útil para tarefas simples que não exigem o cálculo dos valores no repositório de dados, como exibir ou imprimir o conteúdo do repositório de dados.

Não importa o tipo nativo dos dados da coluna no armazenamento de dados; desde que o provedor pode dar suporte a conversão de dados, ele fornecerá os dados no formato de cadeia de caracteres. Se o provedor não der suporte a conversão de tipo de dados nativo para uma cadeia de caracteres (que não é comum), chamada de solicitação retornará o valor de sucesso DB_S_ERRORSOCCURED, e o status para a coluna correspondente será indicar um problema de conversão com DBSTATUS_E_CANTCONVERTVALUE.

Use `CDynamicStringAccessor` métodos para obter informações de coluna. Você pode usar essas informações de coluna para criar um acessador dinamicamente em tempo de execução.

As informações de coluna são armazenadas em um buffer criadas e gerenciadas por esta classe. Obter dados de buffer usando [GetString](../../data/oledb/cdynamicstringaccessor-getstring.md), ou armazená-lo para o buffer usando [SetString](../../data/oledb/cdynamicstringaccessor-setstring.md).

Para obter uma discussão e exemplos de como usar as classes de acessador dinâmico, consulte [usando acessadores dinâmicos](../../data/oledb/using-dynamic-accessors.md).

## <a name="getstring"></a> Cdynamicstringaccessor:: GetString

Recupera os dados da coluna especificada como uma cadeia de caracteres.

### <a name="syntax"></a>Sintaxe

```cpp
BaseType* GetString(DBORDINAL nColumn) const throw();

BaseType* GetString(const CHAR* pColumnName) const throw();

BaseType* GetString(const WCHAR* pColumnName) const throw();
```

#### <a name="parameters"></a>Parâmetros

*nColumn*<br/>
[in] O número da coluna. Os números de coluna começam com 1. Um valor de 0 refere-se para a coluna de indicador, se houver.

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o valor de cadeia de caracteres recuperados da coluna especificada. O valor é do tipo `BaseType`, que estará **CHAR** ou **WCHAR** dependendo se Unicode é definida ou não. Retorna NULL se a coluna especificada não for encontrada.

### <a name="remarks"></a>Comentários

O segundo substituir formulário usa o nome da coluna como uma cadeia de caracteres ANSI. O terceiro substituir formulário usa o nome da coluna como uma cadeia de caracteres Unicode.

## <a name="setstring"></a> Cdynamicstringaccessor:: Setstring

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
[in] O número da coluna. Os números de coluna começam com 1. O valor especial de 0 refere-se para a coluna de indicador, se houver.

*pColumnName*<br/>
[in] Um ponteiro para uma cadeia de caracteres que contém o nome da coluna.

*data*<br/>
[in] Um ponteiro para os dados de cadeia de caracteres a ser gravado para a coluna especificada.

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o valor de cadeia de caracteres para o qual definir a coluna especificada. O valor é do tipo `BaseType`, que estará **CHAR** ou **WCHAR** dependendo se Unicode é definida ou não.

### <a name="remarks"></a>Comentários

O segundo substituir o formulário usa o nome da coluna como uma cadeia de caracteres ANSI e o terceiro substituir o formulário usa o nome da coluna como uma cadeia de caracteres Unicode.

Se _SECURE_ATL for definido para ter um valor diferente de zero, uma falha de asserção de tempo de execução será gerada se a entrada *dados* cadeia for maior que o comprimento máximo permitido da coluna de dados referenciado. Caso contrário, a cadeia de caracteres de entrada será truncada se ele for maior que o comprimento máximo permitido.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)<br/>
[Classe CManualAccessor](../../data/oledb/cmanualaccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicStringAccessorA](../../data/oledb/cdynamicstringaccessora-class.md)<br/>
[Classe CDynamicStringAccessorW](../../data/oledb/cdynamicstringaccessorw-class.md)<br/>
[Classe CXMLAccessor](../../data/oledb/cxmlaccessor-class.md)