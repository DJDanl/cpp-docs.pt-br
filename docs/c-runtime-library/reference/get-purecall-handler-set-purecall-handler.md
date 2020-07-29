---
title: _get_purecall_handler, _set_purecall_handler
ms.date: 11/04/2016
api_name:
- _set_purecall_handler
- _set_purecall_handler_m
- _get_purecall_handler
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _set_purecall_handler
- _set_purecall_handler_m
- set_purecall_handler_m
- set_purecall_handler
- stdlib/_set_purecall_handler
- stdlib/_get_purecall_handler
- _get_purecall_handler
helpviewer_keywords:
- _set_purecall_handler function
- set_purecall_handler function
- purecall_handler
- set_purecall_handler_m function
- _purecall_handler
- _set_purecall_handler_m function
- _get_purecall_handler function
ms.assetid: 2759b878-8afa-4129-86e7-72afc2153d9c
ms.openlocfilehash: 9f21258fa1f6ecd2d1717b00ef2cecaee9c865e2
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216941"
---
# <a name="_get_purecall_handler-_set_purecall_handler"></a>_get_purecall_handler, _set_purecall_handler

Obtém ou define o manipulador de erro para uma chamada de função virtual pura.

## <a name="syntax"></a>Sintaxe

```cpp
typedef void (__cdecl* _purecall_handler)(void);
_purecall_handler __cdecl _get_purecall_handler(void);
_purecall_handler __cdecl _set_purecall_handler(
   _purecall_handler function
);
```

### <a name="parameters"></a>parâmetros

*função*<br/>
A função a ser chamada quando uma função virtual pura é chamada. Uma função **_purecall_handler** deve ter um tipo de retorno void.

## <a name="return-value"></a>Valor retornado

O **_purecall_handler**anterior. Retorna **`nullptr`** se não havia nenhum manipulador anterior.

## <a name="remarks"></a>Comentários

As funções **_get_purecall_handler** e **_set_purecall_handler** são específicas da Microsoft e se aplicam somente ao código C++.

Uma chamada para uma função virtual pura é um erro porque não tem nenhuma implementação. Por padrão, o compilador gera código para invocar uma função de manipulador de erro quando uma função virtual pura é chamada, o que encerra o programa. Você pode instalar sua própria função de manipulador de erro para chamadas de função pura virtual, para capturá-las para fins de depuração ou relatório. Para usar seu próprio manipulador de erro, crie uma função que tenha a assinatura **_purecall_handler** e, em seguida, use **_set_purecall_handler** para torná-la o manipulador atual.

Como há apenas um **_purecall_handler** para cada processo, quando você chama **_set_purecall_handler** ele afeta imediatamente todos os threads. O último chamador em qualquer thread define o manipulador.

Para restaurar o comportamento padrão, chame **_set_purecall_handler** usando um **`nullptr`** argumento.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_purecall_handler**, **_set_purecall_handler**|\<cstdlib> ou \<stdlib.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```cpp
// _set_purecall_handler.cpp
// compile with: /W1
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>

class CDerived;
class CBase
{
public:
   CBase(CDerived *derived): m_pDerived(derived) {};
   ~CBase();
   virtual void function(void) = 0;

   CDerived * m_pDerived;
};

class CDerived : public CBase
{
public:
   CDerived() : CBase(this) {};   // C4355
   virtual void function(void) {};
};

CBase::~CBase()
{
   m_pDerived -> function();
}

void myPurecallHandler(void)
{
   printf("In _purecall_handler.");
   exit(0);
}

int _tmain(int argc, _TCHAR* argv[])
{
   _set_purecall_handler(myPurecallHandler);
   CDerived myDerived;
}
```

```Output
In _purecall_handler.
```

## <a name="see-also"></a>Confira também

[Tratamento de erro](../../c-runtime-library/error-handling-crt.md)<br/>
[_purecall](purecall.md)<br/>
