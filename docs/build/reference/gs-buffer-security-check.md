---
title: "-/GS (verificação de segurança do Buffer) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLWCECompilerTool.BufferSecurityCheck
- VC.Project.VCCLCompilerTool.BufferSecurityCheck
- /GS
dev_langs:
- C++
helpviewer_keywords:
- buffers [C++], buffer overruns
- buffer overruns, compiler /GS switch
- GS compiler option [C++]
- /GS compiler option [C++]
- security check compiler option [C++]
- -GS compiler option [C++]
- buffers [C++], avoiding overruns
ms.assetid: 8d8a5ea1-cd5e-42e1-bc36-66e1cd7e731e
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e5699830a090f42feb92b24ec43fbae36634c4df
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="gs-buffer-security-check"></a>/GS (verificação de segurança do buffer)  
  
Detecta alguns estouros de buffer que substituir o endereço de retorno da função, o endereço do manipulador de exceção ou determinados tipos de parâmetros. Fazendo com que uma saturação de buffer é uma técnica usada por hackers para exploração de código que não impõe restrições de tamanho de buffer.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/GS[-]  
```  
  
## <a name="remarks"></a>Comentários  
  
**/GS** é ativado por padrão. Se você espera que seu aplicativo tenha sem exposição de segurança, use **/GS-**. Para obter mais informações sobre **/GS**, consulte [compilador verifica em profundidade de segurança](http://go.microsoft.com/fwlink/p/?linkid=7260). Para obter mais informações sobre como suprimir a detecção de estouro de buffer, consulte [safebuffers](../../cpp/safebuffers.md).  
  
## <a name="security-checks"></a>Verificações de segurança  
  
Em funções que o compilador reconhece como sujeitos a problemas de saturação de buffer, o compilador aloca espaço na pilha antes do endereço de retorno. Entrada da função, o espaço alocado é carregado com um *cookie de segurança* que é calculada uma vez no carregamento de módulo. Na saída da função e durante a liberação de quadro nos sistemas operacionais de 64 bits, uma função auxiliar é chamada para certificar-se de que o valor do cookie ainda é o mesmo. Um valor diferente indica que uma substituição da pilha pode ter ocorrido. Se um valor diferente for detectado, o processo foi finalizado.  
  
## <a name="gs-buffers"></a>Buffers de GS  
  
É realizada uma verificação de segurança de saturação de buffer em um *buffer GS*. Um buffer de GS pode ser um destes procedimentos:  
  
-   Uma matriz que é maior do que 4 bytes, tem mais de dois elementos e tem um tipo de elemento não é um tipo de ponteiro.  
  
-   Uma estrutura de dados cujo tamanho é de mais de 8 bytes e não contém nenhum ponteiros.  
  
-   Um buffer alocado usando o [alloca](../../c-runtime-library/reference/alloca.md) função.  
  
-   Qualquer classe ou estrutura que contém um buffer GS.  
  
Por exemplo, as seguintes instruções declaram buffers GS.  
  
```cpp  
char buffer[20];  
int buffer[20];  
struct { int a; int b; int c; int d; } myStruct;  
struct { int a; char buf[20]; };  
```  
  
No entanto, as instruções a seguir não declaram buffers GS. As primeiras duas declarações contêm elementos do tipo de ponteiro. As instruções de terceiros e quarta declaram matrizes cujo tamanho é muito pequeno. A quinta instrução declara uma estrutura cujo tamanho em x86 plataforma não é mais de 8 bytes.  
  
```cpp  
char *pBuf[20];  
void *pv[20];  
char buf[4];  
int buf[2];  
struct { int a; int b; };  
```  
  
## <a name="initialize-the-security-cookie"></a>Inicializar o Cookie de segurança  
  
O **/GS** opção de compilador requer que o cookie de segurança seja inicializada antes de qualquer função que usa o cookie é executada. O cookie de segurança deve ser inicializado imediatamente na entrada para um arquivo EXE ou DLL. Isso é feito automaticamente se você usar os pontos de entrada padrão VCRuntime: mainCRTStartup, wmainCRTStartup, WinMainCRTStartup, wWinMainCRTStartup, ou dllmaincrtstartup. Se você usar um ponto de entrada alternativo, você deve inicializar o cookie de segurança manualmente chamando [security_init_cookie](../../c-runtime-library/reference/security-init-cookie.md).  
  
## <a name="what-is-protected"></a>O que está protegido  
  
O **/GS** opção de compilador protege os seguintes itens:  
  
-   O endereço de retorno de uma chamada de função.  
  
-   O endereço de um manipulador de exceção para uma função.  
  
-   Parâmetros de função vulnerável.  
  
Em todas as plataformas, **/GS** tenta detectar saturações de buffer para o endereço de retorno. Saturações de buffer são exploradas mais facilmente em plataformas, como x86 e x64, que usa as convenções de chamada que armazenam o endereço de retorno de uma chamada de função na pilha.  
  
Em x86, se uma função usa um manipulador de exceção, o compilador insere um cookie de segurança para proteger o endereço do manipulador de exceção. O cookie é verificado durante a liberação do quadro.  
  
**/GS** protege *parâmetros vulneráveis* que são passados para uma função. Um parâmetro vulnerável é um ponteiro, referência de C++, um C-estrutura (tipo de C++ POD) que contém um ponteiro ou um buffer GS.  
  
Um parâmetro vulnerável é alocado antes do cookie e variáveis locais. Uma saturação de buffer pode substituir esses parâmetros. E código na função que usa esses parâmetros pode causar um ataque antes que a função retorna e a verificação de segurança é executada. Para minimizar esse risco, o compilador faz uma cópia dos parâmetros vulneráveis durante o prólogo da função e as coloca abaixo da área de armazenamento de buffers.  
  
O compilador não faz cópias dos parâmetros vulneráveis nas seguintes situações:  
  
-   Funções que não contêm um buffer GS.  
  
-   Otimizações ([/O opções](../../build/reference/o-options-optimize-code.md)) não estão habilitados.  
  
-   Funções que têm uma lista de argumentos variáveis (...).  
  
-   Funções que são marcadas com [naked](../../cpp/naked-cpp.md).  
  
-   Funções que contêm o código de assembly embutido na primeira instrução.  
  
-   Um parâmetro é usado somente em modos que são menos prováveis de ser explorada no caso de uma saturação de buffer.  
  
## <a name="what-is-not-protected"></a>O que não está protegido  
  
O **/GS** opção de compilador não protege contra todos os ataques de segurança de saturação de buffer. Por exemplo, se você tiver um buffer e uma vtable em um objeto, uma saturação de buffer pode corromper o vtable.  
  
Mesmo se você usar **/GS**, sempre tentar escrever código seguro com nenhuma saturações de buffer.  
  
### <a name="to-set-this-compiler-option-in-visual-studio"></a>Para definir essa opção do compilador no Visual Studio  
  
1.  Em **Solution Explorer**, clique com o botão direito e, em seguida, clique em **propriedades**.  
  
     Para obter mais informações, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  No **páginas de propriedade** caixa de diálogo, clique o **C/C++** pasta.  
  
3.  Clique o **geração de código** página de propriedades.  
  
4.  Modificar o **verificação de segurança do Buffer** propriedade.  
  
### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BufferSecurityCheck%2A>.  
  
## <a name="example"></a>Exemplo  
  
Este exemplo saturações um buffer. Isso faz com que o aplicativo falhar em tempo de execução.  
  
```C  
// compile with: /c /W1  
#include <cstring>  
#include <stdlib.h>  
#pragma warning(disable : 4996)   // for strcpy use  
  
// Vulnerable function  
void vulnerable(const char *str) {  
   char buffer[10];  
   strcpy(buffer, str); // overrun buffer !!!  
  
   // use a secure CRT function to help prevent buffer overruns  
   // truncate string to fit a 10 byte buffer  
   // strncpy_s(buffer, _countof(buffer), str, _TRUNCATE);  
}  
  
int main() {  
   // declare buffer that is bigger than expected  
   char large_buffer[] = "This string is longer than 10 characters!!";  
   vulnerable(large_buffer);  
}  
```  
  
## <a name="see-also"></a>Consulte também  
  
[Opções do compilador](../../build/reference/compiler-options.md)   
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)