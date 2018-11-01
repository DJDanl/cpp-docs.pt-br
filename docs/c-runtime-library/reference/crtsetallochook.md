---
title: _CrtSetAllocHook
ms.date: 11/04/2016
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
helpviewer_keywords:
- _CrtSetAllocHook function
- CrtSetAllocHook function
ms.assetid: 405df37b-2fd1-42c8-83bc-90887f17f29d
ms.openlocfilehash: cfa466ec4bce6034c15a627ccab4ee4bb0ef8f5b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50533673"
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

Retorna a função de gancho de alocação previamente definida, ou **nulo** se *allocHook* está **nulo**.

## <a name="remarks"></a>Comentários

**Crtsetallochook** permite que um aplicativo vincule sua própria função de alocação ao processo de alocação da memória de biblioteca de depuração em tempo de execução C. Como resultado, todas as chamadas a uma função de alocação de depuração para alocar, realocar ou liberar um bloco de memória disparam uma chamada à função de gancho do aplicativo. **Crtsetallochook** fornece um aplicativo com um método fácil para testar como o aplicativo trata situações de memória insuficiente, a capacidade de examinar padrões de alocação e a oportunidade de registrar informações de alocação para mais tarde análise. Quando [Debug](../../c-runtime-library/debug.md) não está definido, as chamadas a **crtsetallochook** são removidas durante o pré-processamento.

O **crtsetallochook** função instala a nova função de alocação definida pelo cliente especificada em *allocHook* e retorna a função de gancho definida anteriormente. O seguinte exemplo demonstra como um gancho de alocação definido pelo cliente deve ser prototipado:

```C
int YourAllocHook( int allocType, void *userData, size_t size,
                   int blockType, long requestNumber,
                   const unsigned char *filename, int lineNumber);
```

O **allocType** argumento especifica o tipo de operação de alocação (**hook_alloc**, **hook_realloc**, e **hook_free**) que disparou a chamada à função de gancho da alocação. Quando o tipo de alocação de gatilho é **hook_free**, *userData* é um ponteiro para a seção de dados de usuário do bloco de memória prestes a ser liberado. No entanto, quando o tipo de alocação de gatilho estiver **hook_alloc** ou **hook_realloc**, *userData* é **nulo** porque o bloco de memória não foi alocado ainda.

*tamanho* Especifica o tamanho da memória do bloco em bytes, *blockType* indica o tipo do bloco de memória *requestNumber* é o número de ordem de alocação de objeto do bloco de memória e, se disponível, *filename* e **lineNumber** especificar o origem arquivo nome e número de linha em que a operação de alocação de gatilho foi iniciada.

Depois que a função de gancho concluir o processamento, ela deve retornar um valor booliano, que explica ao processo principal de alocação em tempo de execução C como continuar. Quando a função de gancho deseja que o processo de alocação principal continue como se a função de gancho nunca tivesse sido chamada e, em seguida, a função de gancho deverá retornar **verdadeira**. Isso faz com que a operação de alocação de gatilho original seja executada. Ao usar essa implementação, a função de gancho pode coletar e salvar as informações de alocação para análise posterior, sem interferir na operação de alocação atual ou no estado do heap de depuração.

Quando a função de gancho deseja que o processo de alocação principal continue como se a operação de alocação de gatilho foi chamada e falhado, a função de gancho deverá retornar **falsos**. Ao usar essa implementação, a função de gancho pode simular uma ampla variedade de condições de memória e estados de heap de depuração para testar como o aplicativo manipula cada situação.

Para limpar a função de gancho, passe **nulo** à **crtsetallochook**.

Para obter mais informações sobre como **crtsetallochook** pode ser usado com outras funções de gerenciamento de memória ou como escrever suas próprias funções de gancho definidas pelo cliente, consulte [gravação da função de gancho de depuração](/visualstudio/debugger/debug-hook-function-writing).

> [!NOTE]
> **Crtsetallochook** não é suportado nos **/clr: pure**. O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e removidas no Visual Studio 2017.

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
