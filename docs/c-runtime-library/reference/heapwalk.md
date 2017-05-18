---
title: _heapwalk | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _heapwalk
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
- api-ms-win-crt-heap-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- heapwalk
- _heapwalk
dev_langs:
- C++
helpviewer_keywords:
- debugging [CRT], heap-related problems
- heapwalk function
- _heapwalk function
ms.assetid: 2df67649-fb00-4570-a8b1-a4eca5738744
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 936ca2f3f4e4f2fb57dd730f5a58927d08d6207f
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="heapwalk"></a>_heapwalk
Percorre o heap e retorna informações sobre a próxima entrada.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Windows Runtime, exceto em builds de depuração. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _heapwalk(   
   _HEAPINFO *entryinfo   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `entryinfo`  
 Buffer que conterá informações do heap.  
  
## <a name="return-value"></a>Valor de retorno  
 `_heapwalk` retorna uma das seguintes constantes de manifesto de inteiro definidas em Malloc.h.  
  
 `_HEAPBADBEGIN`  
 As informações do cabeçalho inicial são inválidas ou não foram encontradas.  
  
 `_HEAPBADNODE`  
 Heap danificado ou nó inválido encontrado.  
  
 `_HEAPBADPTR`  
O campo  `_pentry` da estrutura `_HEAPINFO` não contém um ponteiro válido para o heap ou `entryinfo` é um ponteiro nulo.  
  
 `_HEAPEND`  
 Fim do heap alcançado com êxito.  
  
 `_HEAPEMPTY`  
 Heap não inicializado.  
  
 `_HEAPOK`  
 Nenhum erro até o momento; `entryinfo` é atualizado com informações sobre a próxima entrada do heap.  
  
 Além disso, se ocorrer um erro, `_heapwalk` definirá `errno` como `ENOSYS`.  
  
## <a name="remarks"></a>Comentários  
 A função `_heapwalk` ajuda a depurar problemas relacionados ao heap em programas. A função percorre o heap, passando por uma entrada por chamada e retorna um ponteiro para uma estrutura do tipo `_HEAPINFO` que contém informações sobre a entrada de heap seguinte. O tipo `_HEAPINFO`, definido em Malloc.h, contém os seguintes elementos.  
  
 `int *_pentry`  
 Ponto de entrada do heap.  
  
 `size_t _size`  
 Tamanho da entrada do heap.  
  
 `int _useflag`  
 Sinalizador que indica se a entrada do heap está sendo utilizada.  
  
 Uma chamada para `_heapwalk` que retorna `_HEAPOK` armazena o tamanho da entrada no campo `_size` e define o campo `_useflag` como `_FREEENTRY` ou `_USEDENTRY` (ambos são constantes definidas em Malloc.h). Para obter essas informações sobre a primeira entrada no heap, passe `_heapwalk` um ponteiro para uma estrutura `_HEAPINFO` cujo membro `_pentry` é `NULL`. Se o sistema operacional não der suporte a `_heapwalk` (por exemplo, Windows 98), a função retornará `_HEAPEND` e definirá `errno` como `ENOSYS`.  
  
 Esta função valida seu parâmetro. Se `entryinfo` for um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e a função retornará `_HEAPBADPTR`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_heapwalk`|\<malloc.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_heapwalk.c  
  
// This program "walks" the heap, starting  
// at the beginning (_pentry = NULL). It prints out each  
// heap entry's use, location, and size. It also prints  
// out information about the overall state of the heap as  
// soon as _heapwalk returns a value other than _HEAPOK  
// or if the loop has iterated 100 times.  
  
#include <stdio.h>  
#include <malloc.h>  
  
void heapdump(void);  
  
int main(void)  
{  
    char *buffer;  
  
    heapdump();  
    if((buffer = (char *)malloc(59)) != NULL)  
    {  
        heapdump();  
        free(buffer);  
    }  
    heapdump();  
}  
  
void heapdump(void)  
{  
    _HEAPINFO hinfo;  
    int heapstatus;  
    int numLoops;  
    hinfo._pentry = NULL;  
    numLoops = 0;  
    while((heapstatus = _heapwalk(&hinfo)) == _HEAPOK &&  
          numLoops < 100)  
    {  
        printf("%6s block at %Fp of size %4.4X\n",  
               (hinfo._useflag == _USEDENTRY ? "USED" : "FREE"),  
               hinfo._pentry, hinfo._size);  
        numLoops++;  
    }  
  
    switch(heapstatus)  
    {  
    case _HEAPEMPTY:  
        printf("OK - empty heap\n");  
        break;  
    case _HEAPEND:  
        printf("OK - end of heap\n");  
        break;  
    case _HEAPBADPTR:  
        printf("ERROR - bad pointer to heap\n");  
        break;  
    case _HEAPBADBEGIN:  
        printf("ERROR - bad start of heap\n");  
        break;  
    case _HEAPBADNODE:  
        printf("ERROR - bad node in heap\n");  
        break;  
    }  
}  
```  
  
```Output  
  USED block at 00310650 of size 0100  
  USED block at 00310758 of size 0800  
  USED block at 00310F60 of size 0080  
  FREE block at 00310FF0 of size 0398  
  USED block at 00311390 of size 000D  
  USED block at 003113A8 of size 00B4  
  USED block at 00311468 of size 0034  
  USED block at 003114A8 of size 0039  
...  
  USED block at 00312228 of size 0010  
  USED block at 00312240 of size 1000  
  FREE block at 00313250 of size 1DB0  
OK - end of heap  
```  
  
## <a name="see-also"></a>Consulte também  
 [Alocação de Memória](../../c-runtime-library/memory-allocation.md)   
 [_heapadd](../../c-runtime-library/heapadd.md)   
 [_heapchk](../../c-runtime-library/reference/heapchk.md)   
 [_heapmin](../../c-runtime-library/reference/heapmin.md)   
 [_heapset](../../c-runtime-library/heapset.md)
