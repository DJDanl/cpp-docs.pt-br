---
title: _CrtSetAllocHook | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _CrtSetAllocHook
apilocation:
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
apitype: DLLExport
f1_keywords:
- _CrtSetAllocHook
- CrtSetAllocHook
dev_langs:
- C++
helpviewer_keywords:
- _CrtSetAllocHook function
- CrtSetAllocHook function
ms.assetid: 405df37b-2fd1-42c8-83bc-90887f17f29d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8d86072ceb41b966adfca298152b6209450aace3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="crtsetallochook"></a>_CrtSetAllocHook

Instala uma função de alocação definida pelo cliente vinculando-a ao processo de alocação de memória de depuração em tempo de execução C (somente versão de depuração).

## <a name="syntax"></a>Sintaxe

```C
_CRT_ALLOC_HOOK _CrtSetAllocHook(
   _CRT_ALLOC_HOOK allocHook
);
```

### <a name="parameters"></a>Parâmetros

*allocHook*<br/>
Nova função de alocação definida pelo cliente a ser vinculada ao processo de alocação de memória de depuração em tempo de execução C.

## <a name="return-value"></a>Valor de retorno

Retorna a função de gancho de alocação previamente definido, ou **nulo** se *allocHook* é **nulo**.

## <a name="remarks"></a>Comentários

**Crtsetallochook** permite que um aplicativo conectar-se com sua própria função de alocação no processo de alocação de memória de biblioteca de C depuração de tempo de execução. Como resultado, todas as chamadas a uma função de alocação de depuração para alocar, realocar ou liberar um bloco de memória disparam uma chamada à função de gancho do aplicativo. **Crtsetallochook** fornece um aplicativo com um método fácil de testar como o aplicativo lida com situações de memória insuficiente, a capacidade de examinar padrões de alocação e a oportunidade de alocação informações de log para mais tarde análise. Quando [Debug](../../c-runtime-library/debug.md) não está definido, chamadas para **crtsetallochook** são removidos durante o pré-processamento.

O **crtsetallochook** função instala a nova função de alocação definida pelo cliente especificada em *allocHook* e retorna a função de gancho definido anteriormente. O seguinte exemplo demonstra como um gancho de alocação definido pelo cliente deve ser prototipado:

```C
int YourAllocHook( int allocType, void *userData, size_t size,
                   int blockType, long requestNumber,
                   const unsigned char *filename, int lineNumber);
```

O **allocType** argumento especifica o tipo de operação de alocação (**_HOOK_ALLOC**, **_HOOK_REALLOC**, e **_HOOK_FREE**) que acionado ao chamar a função de gancho da alocação. Quando o tipo de alocação de disparo é **_HOOK_FREE**, *userData* é um ponteiro para a seção de dados de usuário do bloco de memória prestes a ser liberado. No entanto, quando o tipo de alocação de disparo é **_HOOK_ALLOC** ou **_HOOK_REALLOC**, *userData* é **nulo** porque bloquear a memória não foi alocado ainda.

*tamanho* Especifica o tamanho da memória do bloco em bytes, *blockType* indica o tipo de bloco de memória, *requestNumber* é o número de ordem de alocação de objeto do bloco de memória e, se disponível, *filename* e **lineNumber** especificar o origem arquivo nome e número de linha em que a operação de alocação de disparo foi iniciada.

Depois que a função de gancho concluir o processamento, ela deve retornar um valor booliano, que explica ao processo principal de alocação em tempo de execução C como continuar. Quando a função de gancho quer que o processo de alocação principal para continuar como se nunca tivesse sido chamada de função de gancho, a função de gancho deve retornar **TRUE**. Isso faz com que a operação de alocação de gatilho original seja executada. Ao usar essa implementação, a função de gancho pode coletar e salvar as informações de alocação para análise posterior, sem interferir na operação de alocação atual ou no estado do heap de depuração.

Quando a função de gancho quer que o processo de alocação principal para continuar como se a operação de alocação de disparo foi chamada e falha, a função de gancho deve retornar **FALSE**. Ao usar essa implementação, a função de gancho pode simular uma ampla variedade de condições de memória e estados de heap de depuração para testar como o aplicativo manipula cada situação.

Para limpar a função de gancho, passar **nulo** para **crtsetallochook**.

Para obter mais informações sobre como **crtsetallochook** pode ser usada com outras funções de gerenciamento de memória ou como escrever suas próprias funções de gancho definida pelo cliente, consulte [gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).

> [!NOTE]
> **Crtsetallochook** não tem suporte em **/clr: pure**. O **/clr: pure** e **/CLR: safe** opções do compilador são substituídas no Visual Studio 2015 e removidas no Visual Studio de 2017.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_CrtSetAllocHook**|\<crtdbg.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Somente versões de depuração de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de como usar **crtsetallochook**, consulte [crt_dbg2](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/crt/crt_dbg2).

## <a name="see-also"></a>Consulte também

[Rotinas de depuração](../../c-runtime-library/debug-routines.md)<br/>
[_CrtGetAllocHook](crtgetallochook.md)<br/>
