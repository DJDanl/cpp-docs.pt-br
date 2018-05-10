---
title: code_seg | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- code_seg_CPP
- vc-pragma.code_seg
dev_langs:
- C++
helpviewer_keywords:
- pragmas, code_seg
- code_seg pragma
ms.assetid: bf4faac1-a511-46a6-8d9e-456851d97d56
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f958d1652f82f297ae530c1e24bdf331976e0dc0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="codeseg"></a>code_seg
Especifica o segmento de texto onde as funções são armazenadas no arquivo .obj.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma code_seg( [ [ { push | pop }, ] [ identifier, ] ] [ "segment-name" [, "segment-class" ] )  
```  
  
## <a name="remarks"></a>Comentários  
 A diretiva de pragma `code_seg` não controla o posicionamento do código de objeto gerado por modelos instanciados, nem do código gerado implicitamente pelo compilador (por exemplo, funções membro especiais). Recomendamos que você use o [__declspec(code_seg(...)) ](../cpp/code-seg-declspec.md) de atributo em vez disso, pois ele oferece controle sobre o posicionamento de todo o código de objeto. Isso inclui o código gerado pelo compilador.  
  
 Um *segmento* um obj arquivo é um bloco nomeado de dados que são carregados na memória como uma unidade. Um *segmento texto* é um segmento que contém o código executável. Neste artigo, os termos de *segmento* e *seção* são intercambiáveis.  
  
 A diretiva de pragma `code_seg` informa o compilador para colocar todos os códigos de objeto subsequentes da unidade de tradução em um segmento de texto denominado `segment-name`. Por padrão, o segmento de texto usado para funções em um arquivo .obj é denominado .text.  
  
 Uma diretiva de pragma `code_seg` sem parâmetros redefine o nome do segmento do texto do código de objeto subsequente para .text.  
  
 **Enviar por push** (opcional)  
 Coloca um registro na pilha interna do compilador. Um **push** pode ter um `identifier` e `segment-name`.  
  
 **pop** (opcional)  
 Remove um registro do topo da pilha interna do compilador.  
  
 `identifier` (opcional)  
 Quando usado com **push**, atribui um nome para o registro na pilha do compilador interno. Quando usado com **pop**, pops registros na pilha interna até `identifier` for removido; se `identifier` não foi encontrado na pilha interna, nada é exibido.  
  
 `identifier` permite que vários registros deve ser exibido com apenas um **pop** comando.  
  
 "`segment-name`" (opcional)  
 O nome de um segmento. Quando usado com **pop**, a pilha é exibida e `segment-name` se torna o nome de segmento de texto ativo.  
  
 "`segment-class`" (opcional)  
 Ignorado, mas incluído para compatibilidade com versões C++ anteriores à versão 2.0.  
  
 Você pode usar o [DUMPBIN. EXE](../build/reference/dumpbin-command-line.md) aplicativo para exibir os arquivos. obj. As versões de DUMPBIN para cada arquitetura de destino com suporte estão incluídas em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
## <a name="example"></a>Exemplo  
 Este exemplo mostra como usar a diretiva de pragma `code_seg` para controlar onde o código de objeto será colocado:  
  
```  
// pragma_directive_code_seg.cpp  
void func1() {                  // stored in .text  
}  
  
#pragma code_seg(".my_data1")  
void func2() {                  // stored in my_data1  
}  
  
#pragma code_seg(push, r1, ".my_data2")  
void func3() {                  // stored in my_data2  
}  
  
#pragma code_seg(pop, r1)      // stored in my_data1  
void func4() {  
}  
  
int main() {  
}  
```  
  
 Para obter uma lista de nomes que não deve ser usado para criar uma seção, consulte [/seção](../build/reference/section-specify-section-attributes.md).  
  
 Você também pode especificar seções de dados inicializado ([data_seg](../preprocessor/data-seg.md)), dados foi cancelada ([bss_seg](../preprocessor/bss-seg.md)) e as variáveis constantes ([const_seg](../preprocessor/const-seg.md)).  
  
## <a name="see-also"></a>Consulte também  
 [code_seg ( declspec)](../cpp/code-seg-declspec.md)   
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)