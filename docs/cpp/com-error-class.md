---
title: Classe _com_error
ms.date: 11/04/2016
f1_keywords:
- _com_error
helpviewer_keywords:
- _com_error class
ms.assetid: 70dafa69-b1fb-4a5c-9249-e857e0793d42
ms.openlocfilehash: ace3ac33e4dccd66c0a44095533d657e32b15f1c
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88837808"
---
# <a name="_com_error-class"></a>Classe _com_error

**Específico da Microsoft**

Um objeto **_com_error** representa uma condição de exceção detectada pelas funções de wrapper de tratamento de erros nos arquivos de cabeçalho gerados da biblioteca de tipos ou por uma das classes de suporte com. A classe **_com_error** encapsula o código de erro HRESULT e qualquer `IErrorInfo Interface` objeto associado.

### <a name="construction"></a>Construção

| Nome | Descrição |
|-|-|
|[_com_error](../cpp/com-error-com-error.md)|Constrói um objeto **_com_error** .|

### <a name="operators"></a>Operadores

| Nome | Descrição |
|-|-|
|[operador =](../cpp/com-error-operator-equal.md)|Atribui um objeto de **_com_error** existente para outro.|

### <a name="extractor-functions"></a>Funções de extrator

| Nome | Descrição |
|-|-|
|[Erro](../cpp/com-error-error.md)|Recupera o HRESULT passado para o construtor.|
|[ErrorInfo](../cpp/com-error-errorinfo.md)|Recupera o objeto `IErrorInfo` passado para o construtor.|
|[WCode](../cpp/com-error-wcode.md)|Recupera o código de erro de 16 bits mapeado para o HRESULT encapsulado.|

### <a name="ierrorinfo-functions"></a>Funções IErrorInfo

| Nome | Descrição |
|-|-|
|[Descrição](../cpp/com-error-description.md)|Chama a função `IErrorInfo::GetDescription`.|
|[Identificação](../cpp/com-error-helpcontext.md)|Chama a função `IErrorInfo::GetHelpContext`.|
|[HelpFile](../cpp/com-error-helpfile.md)|Chama a função `IErrorInfo::GetHelpFile`.|
|[Origem](../cpp/com-error-source.md)|Chama a função `IErrorInfo::GetSource`.|
|[GUID](../cpp/com-error-guid.md)|Chama a função `IErrorInfo::GetGUID`.|

### <a name="format-message-extractor"></a>Extrator de mensagem de formato

| Nome | Descrição |
|-|-|
|[ErrorMessage](../cpp/com-error-errormessage.md)|Recupera a mensagem de cadeia de caracteres para HRESULT armazenado no objeto **_com_error** .|

### <a name="exepinfowcode-to-hresult-mappers"></a>Mapeadores de ExepInfo.wCode para HRESULT

| Nome | Descrição |
|-|-|
|[HRESULTToWCode](../cpp/com-error-hresulttowcode.md)|Mapeia 32 bits HRESULT para 16 bits `wCode` .|
|[WCodeToHRESULT](../cpp/com-error-wcodetohresult.md)|Mapeia 16 bits `wCode` para HRESULT de 32 bits.|

**FINAL específico da Microsoft**

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<comdef.h>

`Lib:` comsuppw. lib ou comsuppwd. lib (consulte [/Zc: wchar_t (Wchar_t é o tipo nativo)](../build/reference/zc-wchar-t-wchar-t-is-native-type.md) para obter mais informações)

## <a name="see-also"></a>Confira também

[Classes de suporte de COM do compilador](../cpp/compiler-com-support-classes.md)<br/>
[Interface IErrorInfo](/windows/win32/api/oaidl/nn-oaidl-ierrorinfo)
