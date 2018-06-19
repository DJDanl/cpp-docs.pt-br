---
title: init_seg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.init_seg
- init_seg_CPP
dev_langs:
- C++
helpviewer_keywords:
- pragmas, init_seg
- init_seg pragma
- data segment initializing [C++]
ms.assetid: 40a5898a-5c85-4aa9-8d73-3d967eb13610
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f3be66fc2639253d1bbcfec21f544d5537e084e8
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33840518"
---
# <a name="initseg"></a>init_seg
**Específicas do C++**  
  
 Especifica uma palavra-chave ou uma seção de código que afeta a ordem na qual o código de inicialização é executado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
#pragma init_seg({ compiler | lib | user | "section-name" [, func-name]} )  
```  
  
## <a name="remarks"></a>Comentários  
 O significado dos termos de *segmento* e *seção* são intercambiáveis neste tópico.  
  
 Como a inicialização de objetos globais estáticos pode envolver a execução do código, você deve especificar uma palavra-chave que define quando os objetos devem ser construídos. É particularmente importante usar o **init_seg** pragma em bibliotecas de vínculo dinâmico (DLLs) ou bibliotecas de necessidade de inicialização.  
  
 As opções para o **init_seg** pragma são:  
  
 **Compilador**  
 Reservado para a inicialização da biblioteca em tempo de execução do Microsoft C. Os objetos nesse grupo são construídos primeiro.  
  
 **lib**  
 Disponível para as inicializações de fornecedores de bibliotecas de classes de terceiros. Objetos deste grupo são construídos após as marcadas como **compilador** , mas antes de quaisquer outros usuários.  
  
 **Usuário**  
 Disponível para qualquer usuário. Os objetos nesse grupo são construídos por último.  
  
 *section-name*  
 Permite a especificação explícita da seção de inicialização. Objetos em um usuário especificado *nome da seção* não são criados implicitamente; no entanto, os endereços são colocados na seção nomeada pelo *nome da seção*.  
  
 O nome da seção que você fornecer conterá ponteiros para funções auxiliares que construirão os objetos globais declarados nesse módulo depois do pragma.  
  
 Para obter uma lista de nomes que você não deve usar ao criar uma seção, consulte [/seção](../build/reference/section-specify-section-attributes.md).  
  
 *func-name*  
 Especifique uma função a ser chamada no lugar de `atexit` quando o programa é encerrado. Esta função auxiliar também chama [atexit](../c-runtime-library/reference/atexit.md) com um ponteiro para o destruidor para objeto global. Se você especificar um identificador de função no pragma do formulário,  
  
```  
int __cdecl myexit (void (__cdecl *pf)(void))  
```  
  
 a função será chamada em vez de `atexit` da biblioteca em tempo de execução C. Isso permite compilar uma lista dos destruidores que precisarão ser chamados quando você estiver pronto para destruir os objetos.  
  
 Se você precisar adiar a inicialização (por exemplo, em uma DLL), opte por especificar explicitamente o nome da seção. Em seguida, você deve chamar os construtores para cada objeto estático.  
  
 Não há aspas em torno do identificador para a substituição de `atexit`.  
  
 Os objetos ainda serão colocados nas seções definidas pelos outros pragmas XXX_seg.  
  
 Os objetos que são declarados no módulo não serão inicializados automaticamente pelo tempo de execução C. Você precisará fazer isso por conta própria.  
  
 Por padrão, as seções `init_seg` são somente leitura. Se o nome da seção for .CRT, o compilador modificará silenciosamente o atributo como somente leitura, mesmo se estiver marcado como leitura, gravação.  
  
 Não é possível especificar **init_seg** mais de uma vez em uma unidade de conversão.  
  
 Mesmo se o objeto não tiver um construtor definido pelo usuário, um construtor não definido explicitamente no código, o compilador poderá gerar um (por exemplo para associar ponteiros v-table).  Portanto, seu código precisará chamar o construtor gerado pelo compilador.  
  
## <a name="example"></a>Exemplo  
  
```  
// pragma_directive_init_seg.cpp  
#include <stdio.h>  
#pragma warning(disable : 4075)  
  
typedef void (__cdecl *PF)(void);  
int cxpf = 0;   // number of destructors we need to call  
PF pfx[200];    // pointers to destructors.  
  
int myexit (PF pf) {  
   pfx[cxpf++] = pf;  
   return 0;  
}  
  
struct A {  
   A() { puts("A()"); }  
   ~A() { puts("~A()"); }  
};  
  
// ctor & dtor called by CRT startup code   
// because this is before the pragma init_seg  
A aaaa;   
  
// The order here is important.  
// Section names must be 8 characters or less.  
// The sections with the same name before the $  
// are merged into one section. The order that  
// they are merged is determined by sorting  
// the characters after the $.  
// InitSegStart and InitSegEnd are used to set  
// boundaries so we can find the real functions  
// that we need to call for initialization.  
  
#pragma section(".mine$a", read)  
__declspec(allocate(".mine$a")) const PF InitSegStart = (PF)1;  
  
#pragma section(".mine$z",read)  
__declspec(allocate(".mine$z")) const PF InitSegEnd = (PF)1;  
  
// The comparison for 0 is important.  
// For now, each section is 256 bytes. When they  
// are merged, they are padded with zeros. You  
// can't depend on the section being 256 bytes, but  
// you can depend on it being padded with zeros.  
  
void InitializeObjects () {  
   const PF *x = &InitSegStart;  
   for (++x ; x < &InitSegEnd ; ++x)  
      if (*x) (*x)();  
}  
  
void DestroyObjects () {  
   while (cxpf>0) {  
      --cxpf;  
      (pfx[cxpf])();  
   }  
}  
  
// by default, goes into a read only section  
#pragma init_seg(".mine$m", myexit)  
  
A bbbb;   
A cccc;  
  
int main () {  
   InitializeObjects();  
   DestroyObjects();  
}  
```  
  
```Output  
A()  
A()  
A()  
~A()  
~A()  
~A()  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)