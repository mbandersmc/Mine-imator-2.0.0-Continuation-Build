/*
	NOTE:
	This file was autogenerated by CppGen, changes may be overwritten and forever lost!
	Modify at your own risk!
	
	[ Generated on 2023.06.22 22:32:38 ]
*/

#include "Scripts.hpp"

namespace CppProject
{
	VarType vbuffer_create_cone(RealType rad, VecType tex1, VecType tex2, RealType thflip, RealType tvflip, VarType detail, VarType closed, VarType invert, VarType mapped)
	{
		vbuffer_start();
		tex1.Real(X_) += 0.25;
		tex2.Real(X_) += 0.25;
		RealType i = IntType(0);
		for (IntType _it = 0, _it_max = detail; _it < _it_max; _it++)
		{
			RealType ip;
			RealType n1x, n1y, n2x, n2y;
			RealType x1, y1, x2, y2;
			VecType texsize, texmid;
			ip = i;
			i += 1.0 / detail;
			texsize = point2D_sub(tex2, tex1);
			texmid = point2D_add(tex1, vec2_mul(texsize, 1.0 / 2.0));
			n1x = cos(ip * pi_ * IntType(2));
			n1y = -sin(ip * pi_ * IntType(2));
			n2x = cos(i * pi_ * IntType(2));
			n2y = -sin(i * pi_ * IntType(2));
			x1 = n1x * rad;
			y1 = n1y * rad;
			x2 = n2x * rad;
			y2 = n2y * rad;
			if (invert > 0)
			{
				n1x *= -1.0;
				n1y *= -1.0;
				n2x *= -1.0;
				n2y *= -1.0;
			}
			if (mapped > 0)
			{
				texsize = vec2(0.5 * thflip, tvflip);
				texmid.Real(Y_) = texsize.Real(Y_) / 2.0;
			}
			if (closed > 0)
			{
				if (mapped > 0)
					texmid.Real(X_) = 3.0 / 4.0;
				vbuffer_add_triangle({ IntType(0), IntType(0), -rad, x1, y1, -rad, x2, y2, -rad, texmid.Real(X_), texmid.Real(Y_), texmid.Real(X_) + cos(ip * pi_ * IntType(2)) * (texsize.Real(X_) / 2.0), texmid.Real(Y_) + sin(ip * pi_ * IntType(2)) * (texsize.Real(Y_) / 2.0), texmid.Real(X_) + cos(i * pi_ * IntType(2)) * (texsize.Real(X_) / 2.0), texmid.Real(Y_) + sin(i * pi_ * IntType(2)) * (texsize.Real(Y_) / 2.0), invert });
			}
			if (mapped > 0)
			{
				texmid.Real(X_) = 1.0 / 4.0;
				tex1 = point2D(IntType(0), IntType(0));
				tex2 = point2D(abs(texsize.Real(X_)), abs(texsize.Real(Y_)));
				if (thflip < IntType(0))
				{
					RealType tmp = tex1.Real(X_);
					tex1.Real(X_) = tex2.Real(X_);
					tex2.Real(X_) = tmp;
				}
				if (tvflip < IntType(0))
				{
					RealType tmp = tex1.Real(Y_);
					tex1.Real(Y_) = tex2.Real(Y_);
					tex2.Real(Y_) = tmp;
				}
			}
			if (invert > 0)
			{
				vertex_add({ x2, y2, -rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) + texsize.Real(Y_) });
				vertex_add({ IntType(0), IntType(0), rad, IntType(0), IntType(0), IntType(1), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) });
				vertex_add({ x1, y1, -rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) + texsize.Real(Y_) });
			}
			else
			{
				vertex_add({ IntType(0), IntType(0), rad, IntType(0), IntType(0), IntType(1), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) });
				vertex_add({ x2, y2, -rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) + texsize.Real(Y_) });
				vertex_add({ x1, y1, -rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) + texsize.Real(Y_) });
			}
			
		}
		return vbuffer_done();
	}
	
	VarType vbuffer_create_cube(RealType rad, VecType tex1, VecType tex2, RealType thflip, RealType tvflip, VarType invert, VarType mapped)
	{
		vbuffer_start();
		VecType texsize = point2D(1.0 / 3.0, 1.0 / 2.0);
		if (mapped > 0)
		{
			if (invert > 0)
				tex1.Real(X_) = texsize.Real(X_);
			else
				tex1.Real(X_) = texsize.Real(X_) * IntType(2);
			
			tex1.Real(Y_) = IntType(0);
			tex2 = point2D_add(tex1, texsize);
			if (thflip < IntType(0))
			{
				RealType tmp = tex1.Real(X_);
				tex1.Real(X_) = tex2.Real(X_);
				tex2.Real(X_) = tmp;
			}
			if (tvflip < IntType(0))
			{
				RealType tmp = tex1.Real(Y_);
				tex1.Real(Y_) = tex2.Real(Y_);
				tex2.Real(Y_) = tmp;
			}
		}
		vbuffer_add_triangle({ rad, rad, -rad, rad, rad, rad, rad, -rad, rad, tex1.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex1.Real(Y_), invert });
		vbuffer_add_triangle({ rad, rad, -rad, rad, -rad, rad, rad, -rad, -rad, tex1.Real(X_), tex2.Real(Y_), tex2.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), invert });
		if (mapped > 0)
		{
			if (invert > 0)
				tex1.Real(X_) = texsize.Real(X_) * IntType(2);
			else
				tex1.Real(X_) = texsize.Real(X_);
			
			tex1.Real(Y_) = IntType(0);
			tex2 = point2D_add(tex1, texsize);
			if (thflip < IntType(0))
			{
				RealType tmp = tex1.Real(X_);
				tex1.Real(X_) = tex2.Real(X_);
				tex2.Real(X_) = tmp;
			}
			if (tvflip < IntType(0))
			{
				RealType tmp = tex1.Real(Y_);
				tex1.Real(Y_) = tex2.Real(Y_);
				tex2.Real(Y_) = tmp;
			}
		}
		vbuffer_add_triangle({ -rad, rad, rad, -rad, rad, -rad, -rad, -rad, rad, tex2.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex1.Real(Y_), invert });
		vbuffer_add_triangle({ -rad, -rad, rad, -rad, rad, -rad, -rad, -rad, -rad, tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex2.Real(Y_), invert });
		if (mapped > 0)
		{
			tex1 = point2D(IntType(0), IntType(0));
			tex2 = point2D_add(tex1, texsize);
			if (thflip < IntType(0))
			{
				RealType tmp = tex1.Real(X_);
				tex1.Real(X_) = tex2.Real(X_);
				tex2.Real(X_) = tmp;
			}
			if (tvflip < IntType(0))
			{
				RealType tmp = tex1.Real(Y_);
				tex1.Real(Y_) = tex2.Real(Y_);
				tex2.Real(Y_) = tmp;
			}
		}
		vbuffer_add_triangle({ -rad, rad, rad, rad, rad, rad, rad, rad, -rad, tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), invert });
		vbuffer_add_triangle({ -rad, rad, -rad, -rad, rad, rad, rad, rad, -rad, tex1.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), invert });
		if (mapped > 0)
		{
			tex1 = point2D(IntType(0), texsize.Real(Y_));
			tex2 = point2D_add(tex1, texsize);
			if (thflip < IntType(0))
			{
				RealType tmp = tex1.Real(X_);
				tex1.Real(X_) = tex2.Real(X_);
				tex2.Real(X_) = tmp;
			}
			if (tvflip < IntType(0))
			{
				RealType tmp = tex1.Real(Y_);
				tex1.Real(Y_) = tex2.Real(Y_);
				tex2.Real(Y_) = tmp;
			}
		}
		vbuffer_add_triangle({ rad, -rad, rad, -rad, -rad, rad, rad, -rad, -rad, tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex1.Real(Y_), tex1.Real(X_), tex2.Real(Y_), invert });
		vbuffer_add_triangle({ -rad, -rad, rad, -rad, -rad, -rad, rad, -rad, -rad, tex2.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex2.Real(Y_), invert });
		if (mapped > 0)
		{
			tex1 = texsize;
			tex2 = point2D_add(tex1, texsize);
			if (thflip < IntType(0))
			{
				RealType tmp = tex1.Real(X_);
				tex1.Real(X_) = tex2.Real(X_);
				tex2.Real(X_) = tmp;
			}
			if (tvflip < IntType(0))
			{
				RealType tmp = tex1.Real(Y_);
				tex1.Real(Y_) = tex2.Real(Y_);
				tex2.Real(Y_) = tmp;
			}
		}
		vbuffer_add_triangle({ -rad, -rad, rad, rad, -rad, rad, -rad, rad, rad, tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex1.Real(Y_), tex1.Real(X_), tex2.Real(Y_), invert });
		vbuffer_add_triangle({ rad, -rad, rad, rad, rad, rad, -rad, rad, rad, tex2.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex2.Real(Y_), invert });
		if (mapped > 0)
		{
			tex1 = point2D(texsize.Real(X_) * IntType(2), texsize.Real(Y_));
			tex2 = point2D_add(tex1, texsize);
			if (thflip < IntType(0))
			{
				RealType tmp = tex1.Real(X_);
				tex1.Real(X_) = tex2.Real(X_);
				tex2.Real(X_) = tmp;
			}
			if (tvflip < IntType(0))
			{
				RealType tmp = tex1.Real(Y_);
				tex1.Real(Y_) = tex2.Real(Y_);
				tex2.Real(Y_) = tmp;
			}
		}
		vbuffer_add_triangle({ rad, -rad, -rad, -rad, -rad, -rad, -rad, rad, -rad, tex2.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex1.Real(Y_), invert });
		vbuffer_add_triangle({ rad, rad, -rad, rad, -rad, -rad, -rad, rad, -rad, tex2.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex1.Real(Y_), invert });
		return vbuffer_done();
	}
	
	VarType vbuffer_create_cylinder(RealType rad, VecType tex1, VecType tex2, RealType thflip, RealType tvflip, VarType detail, VarType closed, VarType invert, VarType mapped)
	{
		vbuffer_start();
		tex1.Real(X_) += 0.25;
		tex2.Real(X_) += 0.25;
		RealType i = IntType(0);
		for (IntType _it = 0, _it_max = detail; _it < _it_max; _it++)
		{
			RealType ip;
			RealType n1x, n1y, n2x, n2y;
			RealType x1, y1, x2, y2;
			VecType texsize, texmid;
			ip = i;
			i += 1.0 / detail;
			texsize = point2D_sub(tex2, tex1);
			texmid = point2D_add(tex1, vec2_mul(texsize, 1.0 / 2.0));
			n1x = cos(ip * pi_ * IntType(2));
			n1y = -sin(ip * pi_ * IntType(2));
			n2x = cos(i * pi_ * IntType(2));
			n2y = -sin(i * pi_ * IntType(2));
			x1 = n1x * rad;
			y1 = n1y * rad;
			x2 = n2x * rad;
			y2 = n2y * rad;
			if (invert > 0)
			{
				n1x *= -1.0;
				n1y *= -1.0;
				n2x *= -1.0;
				n2y *= -1.0;
			}
			if (mapped > 0)
			{
				texsize = vec2((1.0 / 3.0) * thflip, tvflip);
				texmid.Real(Y_) = texsize.Real(Y_) / 2.0;
			}
			if (closed > 0)
			{
				if (mapped > 0)
					texmid.Real(X_) = 5.0 / 6.0;
				vbuffer_add_triangle({ IntType(0), IntType(0), -rad, x1, y1, -rad, x2, y2, -rad, texmid.Real(X_), texmid.Real(Y_), texmid.Real(X_) + cos(ip * pi_ * IntType(2)) * (texsize.Real(X_) / 2.0), texmid.Real(Y_) + sin(ip * pi_ * IntType(2)) * (texsize.Real(Y_) / 2.0), texmid.Real(X_) + cos(i * pi_ * IntType(2)) * (texsize.Real(X_) / 2.0), texmid.Real(Y_) + sin(i * pi_ * IntType(2)) * (texsize.Real(Y_) / 2.0), invert });
				if (mapped > 0)
					texmid.Real(X_) = 1.0 / 2.0;
				vbuffer_add_triangle({ IntType(0), IntType(0), rad, x2, y2, rad, x1, y1, rad, texmid.Real(X_), texmid.Real(Y_), texmid.Real(X_) + cos(i * pi_ * IntType(2)) * (texsize.Real(X_) / 2.0), texmid.Real(Y_) - sin(i * pi_ * IntType(2)) * (texsize.Real(Y_) / 2.0), texmid.Real(X_) + cos(ip * pi_ * IntType(2)) * (texsize.Real(X_) / 2.0), texmid.Real(Y_) - sin(ip * pi_ * IntType(2)) * (texsize.Real(Y_) / 2.0), invert });
			}
			if (mapped > 0)
			{
				tex1 = point2D(IntType(0), IntType(0));
				tex2 = point2D(abs(texsize.Real(X_)), abs(texsize.Real(Y_)));
				if (thflip < IntType(0))
				{
					RealType tmp = tex1.Real(X_);
					tex1.Real(X_) = tex2.Real(X_);
					tex2.Real(X_) = tmp;
				}
				if (tvflip < IntType(0))
				{
					RealType tmp = tex1.Real(Y_);
					tex1.Real(Y_) = tex2.Real(Y_);
					tex2.Real(Y_) = tmp;
				}
			}
			if (invert > 0)
			{
				vertex_add({ x1, y1, rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) });
				vertex_add({ x1, y1, -rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) + texsize.Real(Y_) });
				vertex_add({ x2, y2, rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) });
				vertex_add({ x2, y2, -rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) + texsize.Real(Y_) });
				vertex_add({ x2, y2, rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) });
				vertex_add({ x1, y1, -rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) + texsize.Real(Y_) });
			}
			else
			{
				vertex_add({ x1, y1, -rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) + texsize.Real(Y_) });
				vertex_add({ x1, y1, rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) });
				vertex_add({ x2, y2, rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) });
				vertex_add({ x2, y2, rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) });
				vertex_add({ x2, y2, -rad, n2x, n2y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * i, tex1.Real(Y_) + texsize.Real(Y_) });
				vertex_add({ x1, y1, -rad, n1x, n1y, IntType(0), tex1.Real(X_) + texsize.Real(X_) * ip, tex1.Real(Y_) + texsize.Real(Y_) });
			}
			
		}
		return vbuffer_done();
	}
	
	VarType vbuffer_create_path(Scope<obj_timeline> self, IntType path, BoolType small_)
	{
		ArrType points;
		VarType radius, detail, closed, texlength, invert;
		BoolType rail;
		points = ObjType(obj_timeline, path)->path_table;
		radius = ObjType(obj_timeline, path)->path_shape_radius;
		detail = ObjType(obj_timeline, path)->path_shape_detail;
		closed = ObjType(obj_timeline, path)->path_closed;
		rail = !(ObjType(obj_timeline, path)->path_shape_tube > 0);
		texlength = ObjType(obj_timeline, path)->path_shape_tex_length;
		invert = ObjType(obj_timeline, path)->path_shape_invert;
		if (small_)
		{
			radius = IntType(1);
			detail = IntType(4);
			rail = false;
			invert = false;
		}
		vbuffer_start();
		ArrType frames;
		VarType p;
		for (IntType i = IntType(0); i < array_length(VarType::CreateRef(points)); i++)
		{
			p = points.Value(i);
			frames[i] = matrix_create_rotate_to(ArrType::From({ p.Value(PATH_TANGENT_X), p.Value(PATH_TANGENT_Y), p.Value(PATH_TANGENT_Z) }), ArrType::From({ p.Value(PATH_NORMAL_X), p.Value(PATH_NORMAL_Y), p.Value(PATH_NORMAL_Z) }));
		}
		VecType p1, p2, p3, p4;
		VecType n1, n2, n3, n4, nflatp, nflat;
		VecType nn1, nn2, nn3, nn4;
		VecType t1, t2, t3, t4;
		RealType jp, j;
		ArrType ringp;
		RealType length, plength;
		length = IntType(0);
		plength = IntType(0);
		for (IntType i = IntType(0); i < array_length(VarType::CreateRef(frames)) - IntType(1); i++)
		{
			if (!rail)
			{
				jp = IntType(0);
				j = 1.0 / detail;
			}
			else
				jp = .5;
			
			ringp = ArrType::From({ cos(jp * pi_ * IntType(2)), IntType(0), -sin(jp * pi_ * IntType(2)) });
			plength = length;
			length += point3D_distance(points.Value(i), points.Value(i + IntType(1)));
			n1 = vec3_normalize(vec3_mul_matrix(ringp, frames.Value(i)));
			p1 = point3D_add(vec3_mul(n1, radius * points[i][IntType(4)]), points.Value(i));
			n3 = vec3_normalize(vec3_mul_matrix(ringp, frames.Value(i + IntType(1))));
			p3 = point3D_add(vec3_mul(n3, radius * points[i + IntType(1)][IntType(4)]), points.Value(i + IntType(1)));
			jp = IntType(0);
			j = IntType(0);
			while (j < IntType(1))
			{
				if (!rail)
				{
					jp = j;
					j += 1.0 / detail;
				}
				else
					j = IntType(0);
				
				ringp = ArrType::From({ cos(j * pi_ * IntType(2)), IntType(0), -sin(j * pi_ * IntType(2)) });
				n2 = vec3_normalize(vec3_mul_matrix(ringp, frames.Value(i)));
				p2 = point3D_add(vec3_mul(n2, radius * points[i][IntType(4)]), points.Value(i));
				n4 = vec3_normalize(vec3_mul_matrix(ringp, frames.Value(i + IntType(1))));
				p4 = point3D_add(vec3_mul(n4, radius * points[i + IntType(1)][IntType(4)]), points.Value(i + IntType(1)));
				if (rail)
				{
					t1 = vec2(IntType(0), plength / texlength);
					t2 = vec2(IntType(1), plength / texlength);
					t3 = vec2(IntType(0), length / texlength);
					t4 = vec2(IntType(1), length / texlength);
					n1 = ArrType::From({ frames[i][IntType(8)], frames[i][IntType(9)], frames[i][IntType(10)] });
					n2 = n1;
					n3 = ArrType::From({ frames[i + IntType(1)][IntType(8)], frames[i + IntType(1)][IntType(9)], frames[i + IntType(1)][IntType(10)] });
					n4 = n3;
				}
				else
				{
					t1 = vec2(jp, plength / texlength);
					t2 = vec2(j, plength / texlength);
					t3 = vec2(jp, length / texlength);
					t4 = vec2(j, length / texlength);
				}
				
				t1.Real(X_) /= 3.0;
				t2.Real(X_) /= 3.0;
				t3.Real(X_) /= 3.0;
				t4.Real(X_) /= 3.0;
				nn1 = n1;
				nn2 = n2;
				nn3 = n3;
				nn4 = n4;
				if (invert > 0)
				{
					nn1 = vec3_mul(nn1, -IntType(1));
					nn2 = vec3_mul(nn2, -IntType(1));
					nn3 = vec3_mul(nn3, -IntType(1));
					nn4 = vec3_mul(nn4, -IntType(1));
				}
				if (ObjType(obj_timeline, path)->path_shape_smooth_segments > 0 && !(ObjType(obj_timeline, path)->path_shape_smooth_ring > 0))
				{
					nflatp = vec3_normalize(vec3_add(nn1, nn2));
					nflat = vec3_normalize(vec3_add(nn3, nn4));
					nn1 = nflatp;
					nn2 = nflatp;
					nn3 = nflat;
					nn4 = nflat;
				}
				else
					if (!(ObjType(obj_timeline, path)->path_shape_smooth_segments > 0) && ObjType(obj_timeline, path)->path_shape_smooth_ring > 0)
					{
						nflatp = vec3_normalize(vec3_add(nn1, nn3));
						nflat = vec3_normalize(vec3_add(nn2, nn4));
						nn1 = nflatp;
						nn2 = nflat;
						nn3 = nflatp;
						nn4 = nflat;
					}
					else
						if (!(self->path_shape_smooth_segments > 0) && !(self->path_shape_smooth_ring > 0))
						{
							nflat = vec3_normalize(vec3_add(vec3_add(vec3_add(nn1, nn2), nn3), nn4));
							nn1 = nflat;
							nn2 = nflat;
							nn3 = nflat;
							nn4 = nflat;
						}
				
				
				if (invert > 0)
				{
					vbuffer_add_triangle({ p2, p1, p4, t4, t1, t2, nn2, nn1, nn4 });
					vbuffer_add_triangle({ p1, p3, p4, t4, t3, t1, nn1, nn3, nn4 });
				}
				else
				{
					vbuffer_add_triangle({ p4, p1, p2, t4, t1, t2, nn4, nn1, nn2 });
					vbuffer_add_triangle({ p4, p3, p1, t4, t3, t1, nn4, nn3, nn1 });
				}
				
				if (rail)
					break;
				if (!(closed > 0))
				{
					t1 = ArrType::From({ (cos((jp + .25) * pi_ * IntType(2)) + 1.0) / 2.0, (sin((jp + .25) * pi_ * IntType(2)) + 1.0) / 2.0 });
					t2 = ArrType::From({ (cos((j + .25) * pi_ * IntType(2)) + 1.0) / 2.0, (sin((j + .25) * pi_ * IntType(2)) + 1.0) / 2.0 });
					t3 = ArrType::From({ .5, .5 });
					t1.Real(X_) = (t1.Real(X_) / 3.0) + (1.0 / 3.0);
					t2.Real(X_) = (t2.Real(X_) / 3.0) + (1.0 / 3.0);
					t3.Real(X_) = (t3.Real(X_) / 3.0) + (1.0 / 3.0);
					if (i == IntType(0))
					{
						if (invert > 0)
							vbuffer_add_triangle({ p2, points.Value(i), p1, t1, t3, t2 });
						else
							vbuffer_add_triangle({ p1, points.Value(i), p2, t1, t3, t2 });
						
					}
					if (i == (array_length(VarType::CreateRef(points)) - IntType(2)))
					{
						t1.Real(X_) += (1.0 / 3.0);
						t2.Real(X_) += (1.0 / 3.0);
						t3.Real(X_) += (1.0 / 3.0);
						if (invert > 0)
							vbuffer_add_triangle({ p3, points.Value(i + IntType(1)), p4, t2, t3, t1 });
						else
							vbuffer_add_triangle({ p4, points.Value(i + IntType(1)), p3, t2, t3, t1 });
						
					}
				}
				p1 = p2;
				p3 = p4;
				n1 = n2;
				n3 = n4;
			}
			
		}
		return vbuffer_done();
	}
	
	VarType vbuffer_create_sphere(RealType rad, VecType tex1, VecType tex2, VarType detail, VarType invert)
	{
		vbuffer_start();
		tex1.Real(X_) += 0.25;
		tex2.Real(X_) += 0.25;
		RealType i = IntType(0);
		for (IntType _it = 0, _it_max = detail; _it < _it_max; _it++)
		{
			RealType ip, j;
			ip = i;
			i += 1.0 / detail;
			j = IntType(0);
			for (IntType _it = 0, _it_max = detail - IntType(2); _it < _it_max; _it++)
			{
				RealType jp;
				RealType n1x, n1y, n1z, n2x, n2y, n2z, n3x, n3y, n3z, n4x, n4y, n4z;
				RealType x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
				VecType texsize, texmid;
				RealType n;
				jp = j;
				j += 1.0 / (detail - IntType(2));
				texsize = point2D_sub(tex2, tex1);
				texmid = point2D_add(tex1, vec2_mul(texsize, 1.0 / 2.0));
				n = negate(invert);
				n1x = sin(ip * pi_ * IntType(2)) * sin(jp * pi_);
				n1y = -cos(ip * pi_ * IntType(2)) * sin(jp * pi_);
				n1z = -cos(jp * pi_);
				n2x = sin(ip * pi_ * IntType(2)) * sin(j * pi_);
				n2y = -cos(ip * pi_ * IntType(2)) * sin(j * pi_);
				n2z = -cos(j * pi_);
				n3x = sin(i * pi_ * IntType(2)) * sin(jp * pi_);
				n3y = -cos(i * pi_ * IntType(2)) * sin(jp * pi_);
				n3z = -cos(jp * pi_);
				n4x = sin(i * pi_ * IntType(2)) * sin(j * pi_);
				n4y = -cos(i * pi_ * IntType(2)) * sin(j * pi_);
				n4z = -cos(j * pi_);
				x1 = n1x * rad;
				y1 = n1y * rad;
				z1 = n1z * rad;
				x2 = n2x * rad;
				y2 = n2y * rad;
				z2 = n2z * rad;
				x3 = n3x * rad;
				y3 = n3y * rad;
				z3 = n3z * rad;
				x4 = n4x * rad;
				y4 = n4y * rad;
				z4 = n4z * rad;
				if (jp > IntType(0))
				{
					if (invert > 0)
					{
						vertex_add({ x3, y3, z3, n3x * n, n3y * n, n3z * n, tex2.Real(X_) - i * texsize.Real(X_), texmid.Real(Y_) - n3z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x1, y1, z1, n1x * n, n1y * n, n1z * n, tex2.Real(X_) - ip * texsize.Real(X_), texmid.Real(Y_) - n1z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x4, y4, z4, n4x * n, n4y * n, n4z * n, tex2.Real(X_) - i * texsize.Real(X_), texmid.Real(Y_) - n4z * (texsize.Real(Y_) / 2.0) });
					}
					else
					{
						vertex_add({ x1, y1, z1, n1x * n, n1y * n, n1z * n, tex2.Real(X_) - ip * texsize.Real(X_), texmid.Real(Y_) - n1z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x3, y3, z3, n3x * n, n3y * n, n3z * n, tex2.Real(X_) - i * texsize.Real(X_), texmid.Real(Y_) - n3z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x4, y4, z4, n4x * n, n4y * n, n4z * n, tex2.Real(X_) - i * texsize.Real(X_), texmid.Real(Y_) - n4z * (texsize.Real(Y_) / 2.0) });
					}
					
				}
				if (j < IntType(1))
				{
					if (invert > 0)
					{
						vertex_add({ x4, y4, z4, n4x * n, n4y * n, n4z * n, tex2.Real(X_) - i * texsize.Real(X_), texmid.Real(Y_) - n4z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x1, y1, z1, n1x * n, n1y * n, n1z * n, tex2.Real(X_) - ip * texsize.Real(X_), texmid.Real(Y_) - n1z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x2, y2, z2, n2x * n, n2y * n, n2z * n, tex2.Real(X_) - ip * texsize.Real(X_), texmid.Real(Y_) - n2z * (texsize.Real(Y_) / 2.0) });
					}
					else
					{
						vertex_add({ x1, y1, z1, n1x * n, n1y * n, n1z * n, tex2.Real(X_) - ip * texsize.Real(X_), texmid.Real(Y_) - n1z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x4, y4, z4, n4x * n, n4y * n, n4z * n, tex2.Real(X_) - i * texsize.Real(X_), texmid.Real(Y_) - n4z * (texsize.Real(Y_) / 2.0) });
						vertex_add({ x2, y2, z2, n2x * n, n2y * n, n2z * n, tex2.Real(X_) - ip * texsize.Real(X_), texmid.Real(Y_) - n2z * (texsize.Real(Y_) / 2.0) });
					}
					
				}
			}
		}
		return vbuffer_done();
	}
	
	VarType vbuffer_create_surface(RealType rad, VecType tex1, VecType tex2, VarType invert)
	{
		vbuffer_start();
		vbuffer_add_triangle({ -rad, IntType(0), rad, rad, IntType(0), rad, rad, IntType(0), -rad, tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), invert });
		vbuffer_add_triangle({ -rad, IntType(0), -rad, -rad, IntType(0), rad, rad, IntType(0), -rad, tex1.Real(X_), tex2.Real(Y_), tex1.Real(X_), tex1.Real(Y_), tex2.Real(X_), tex2.Real(Y_), invert });
		return vbuffer_done();
	}
	
	void vbuffer_destroy(VarType vbuf)
	{
		vertex_delete_buffer((IntType)(vbuf));
	}
	
	VarType vbuffer_done(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		VarType vbuffer = global::vbuffer_current;
		if (argument_count > IntType(0))
			global::vbuffer_current = argument[IntType(0)];
		vertex_end((IntType)(vbuffer));
		vbuffer = vbuffer_generate_tangents(vbuffer);
		vertex_freeze((IntType)(vbuffer));
		return vbuffer;
	}
	
	VarType vbuffer_generate_tangents(VarType vbuffer)
	{
		if (is_cpp() || dev_mode_skip_tangents)
			return vbuffer;
		IntType size, seekend;
		ArrType p, uv, seekpos;
		VecType t;
		VecType edge1, edge2, deltaUV1, deltaUV2;
		RealType f;
		size = vertex_get_number((IntType)(vbuffer));
		if (size < IntType(4))
			return vbuffer;
		IntType vertex_data = buffer_create_from_vertex_buffer((IntType)(vbuffer), buffer_grow, IntType(1));
		vbuffer_destroy(vbuffer);
		for (RealType i = IntType(0); i < size; i += IntType(3))
		{
			for (IntType j = IntType(0); j <= IntType(2); j++)
			{
				p[j][X_] = buffer_read(vertex_data, buffer_f32);
				p[j][Y_] = buffer_read(vertex_data, buffer_f32);
				p[j][Z_] = buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_u32);
				uv[j][X_] = buffer_read(vertex_data, buffer_f32);
				uv[j][Y_] = buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				seekpos[j] = buffer_tell(vertex_data);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
				buffer_read(vertex_data, buffer_f32);
			}
			seekend = buffer_tell(vertex_data);
			if (i == IntType(0))
				continue;
			edge1 = point3D_sub(p.Value(IntType(1)), p.Value(IntType(0)));
			edge2 = point3D_sub(p.Value(IntType(2)), p.Value(IntType(0)));
			deltaUV1 = point2D_sub(uv.Value(IntType(1)), uv.Value(IntType(0)));
			deltaUV2 = point2D_sub(uv.Value(IntType(2)), uv.Value(IntType(0)));
			f = 1.0 / (deltaUV1.Real(X_) * deltaUV2.Real(Y_) - deltaUV1.Real(Y_) * deltaUV2.Real(X_));
			t = vec3_normalize(vec3_mul(vec3_sub(vec3_mul(edge1, deltaUV2.Real(Y_)), vec3_mul(edge2, deltaUV1.Real(Y_))), f));
			for (IntType j = IntType(0); j <= IntType(2); j++)
			{
				buffer_seek(vertex_data, buffer_seek_start, seekpos.Value(j));
				buffer_write(vertex_data, buffer_f32, t.Real(X_));
				buffer_write(vertex_data, buffer_f32, t.Real(Y_));
				buffer_write(vertex_data, buffer_f32, t.Real(Z_));
			}
			buffer_seek(vertex_data, buffer_seek_start, seekend);
		}
		vbuffer = vertex_create_buffer_from_buffer(vertex_data, global::vertex_format);
		buffer_delete(vertex_data);
		return vbuffer;
	}
	
	BoolType vbuffer_is_empty(VarType vbuf)
	{
		return (vertex_get_number((IntType)(vbuf)) == (is_cpp() ? IntType(0) : IntType(3)));
	}
	
	BoolType vbuffer_render(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		MatrixType mat;
		VarType vbuf = argument[IntType(0)];
		if (vbuf == null_)
			return false;
		if (argument_count > IntType(1))
		{
			VarType pos, rot, sca;
			if (argument_count > IntType(1))
				pos = argument[IntType(1)];
			else
				pos = point3D(IntType(0), IntType(0), IntType(0));
			
			if (argument_count > IntType(2))
				rot = argument[IntType(2)];
			else
				rot = vec3(IntType(0), IntType(0), IntType(0));
			
			if (argument_count > IntType(3))
				sca = argument[IntType(3)];
			else
				sca = vec3(IntType(1), IntType(1), IntType(1));
			
			mat = matrix_get(matrix_world);
			matrix_set(matrix_world, matrix_create(pos, rot, sca));
		}
		vertex_submit((IntType)(vbuf), pr_trianglelist, -IntType(1));
		if (argument_count > IntType(1))
			matrix_set(matrix_world, mat);
		return false;
	}
	
	void vbuffer_render_matrix(VarType vbuf, MatrixType mat)
	{
		matrix_set(matrix_world, mat);
		vertex_submit((IntType)(vbuf), pr_trianglelist, -IntType(1));
		matrix_world_reset();
	}
	
	VarType vbuffer_start()
	{
		global::vbuffer_current = vertex_create_buffer();
		vertex_begin((IntType)(global::vbuffer_current), global::vertex_format);
		if (!is_cpp())
			for (IntType _it = 0, _it_max = IntType(3); _it < _it_max; _it++)
				vertex_add({ IntType(0), IntType(0), IntType(0), IntType(0), IntType(0), IntType(0), IntType(0), IntType(0) });
		return global::vbuffer_current;
	}
	
	VarType vec3_direction(VarType from, VarType to)
	{
		VecType v = vec3_normalize(point3D_sub(to, from));
		if (vec3_length(v) == IntType(0))
			return ArrType::From({ IntType(0), IntType(1), IntType(0) });
		else
			return v;
		
		return VarType();
	}
	
	VecType vec3_normal(VarType vec, RealType angle)
	{
		RealType xx, yy, zz, cx, cy;
		VecType t;
		xx = vec.Value(X_);
		yy = vec.Value(Y_);
		zz = vec.Value(Z_);
		if (abs(zz) != IntType(1))
		{
			cx = lengthdir_x(1.0, angle) / sqrt(xx * xx + yy * yy + zz * zz);
			cy = lengthdir_y(1.0, angle);
			t.Real(Z_) = cx * (xx * xx + yy * yy);
			t.Real(Y_) = cy * xx - cx * yy * zz;
			t.Real(X_) = -cx * xx * zz - cy * yy;
			return vec3_normalize(t);
		}
		else
			return ArrType::From({ lengthdir_x(1.0, angle), lengthdir_y(1.0, angle), IntType(0) });
		
		return VecType();
	}
	
	VecType vec3_project_ray(VecType point)
	{
		RealType px, py;
		VecType rayclip, rayeye, raywor;
		px = -(point.Real(X_) * IntType(2) - IntType(1));
		py = point.Real(Y_) * IntType(2) - IntType(1);
		rayclip = vec4(px, py, -IntType(1), IntType(1));
		rayeye = point4D_mul_matrix(rayclip, matrix_inverse(global::proj_matrix));
		rayeye = vec4(rayeye.Real(X_), rayeye.Real(Y_), -IntType(1), IntType(0));
		raywor = point4D_mul_matrix(rayeye, matrix_inverse(global::view_matrix));
		return vec3_normalize(vec3(raywor.Real(X_), raywor.Real(Y_), raywor.Real(Z_)));
	}
	
	VecType vec3_reflect(VarType v, VarType n)
	{
		return vec3_sub(v, vec3_mul(vec3_mul(n, vec3_dot(v, n)), IntType(2)));
	}
	
	VecType vec3_rotate_axis_angle(VarType v, VarType axis, RealType angle)
	{
		VecType d, r;
		d = vec3_mul(axis, vec3_dot(v, axis));
		r = vec3_sub(v, d);
		return vec3_add(d, vec3_add(vec3_mul(r, cos(angle)), vec3_mul(vec3_cross(axis, r), sin(angle))));
	}
	
	void vertex_add(VarArgs argument)
	{
		IntType argument_count = argument.Size();
		VarType xx, yy, zz;
		if (argument_count < IntType(8))
		{
			VarType pos, texcoord;
			VecType normal;
			pos = argument[IntType(0)];
			normal = vec3_normalize(argument[IntType(1)]);
			texcoord = argument[IntType(2)];
			xx = pos.Value(X_);
			yy = pos.Value(Y_);
			zz = pos.Value(Z_);
			vertex_position_3d((IntType)(global::vbuffer_current), xx, yy, pos.Value(Z_));
			vertex_normal((IntType)(global::vbuffer_current), normal.Real(X_), normal.Real(Y_), normal.Real(Z_));
			vertex_color((IntType)(global::vbuffer_current), (IntType)(global::vertex_rgb), global::vertex_alpha);
			vertex_texcoord((IntType)(global::vbuffer_current), texcoord.Value(X_), texcoord.Value(Y_));
		}
		else
		{
			xx = argument[IntType(0)];
			yy = argument[IntType(1)];
			zz = argument[IntType(2)];
			VecType normal = vec3_normalize(ArrType::From({ argument[IntType(3)], argument[IntType(4)], argument[IntType(5)] }));
			vertex_position_3d((IntType)(global::vbuffer_current), xx, yy, zz);
			vertex_normal((IntType)(global::vbuffer_current), normal.Real(X_), normal.Real(Y_), normal.Real(Z_));
			vertex_color((IntType)(global::vbuffer_current), (IntType)(global::vertex_rgb), global::vertex_alpha);
			vertex_texcoord((IntType)(global::vbuffer_current), argument[IntType(6)], argument[IntType(7)]);
		}
		
		RealType wavexy, wavez;
		wavexy = IntType(0);
		wavez = IntType(0);
		if (global::vertex_wave != e_vertex_wave_NONE)
		{
			if ((global::vertex_wave_zmin == null_ || zz > global::vertex_wave_zmin) && (global::vertex_wave_zmax == null_ || zz < global::vertex_wave_zmax))
			{
				if (global::vertex_wave == e_vertex_wave_ALL)
				{
					wavexy = IntType(1);
					wavez = IntType(1);
				}
				else
					if (global::vertex_wave == e_vertex_wave_Z_ONLY)
						wavez = IntType(1);
				
			}
			vertex_float4((IntType)(global::vbuffer_current), wavexy, wavez, global::vertex_emissive, global::vertex_subsurface);
		}
		else
			vertex_float4((IntType)(global::vbuffer_current), 0.0, 0.0, global::vertex_emissive, global::vertex_subsurface);
		
		vertex_float3((IntType)(global::vbuffer_current), 0.0, 0.0, 0.0);
	}
	
	void vertex_format_startup(ScopeAny self)
	{
		log({ /*"Create vertex format"*/ STR(3873) });
		vertex_format_begin();
		vertex_format_add_position_3d();
		vertex_format_add_normal();
		vertex_format_add_colour();
		vertex_format_add_texcoord();
		vertex_format_add_custom(vertex_type_float4, vertex_usage_texcoord);
		vertex_format_add_custom((IntType)(sVar(vertex_type_float3)), vertex_usage_texcoord);
		global::vertex_format = vertex_format_end();
		global::vertex_rgb = c_white;
		global::vertex_alpha = IntType(1);
		global::vertex_wave = e_vertex_wave_NONE;
		global::vertex_wave_zmin = null_;
		global::vertex_wave_zmax = null_;
		global::vertex_emissive = IntType(0);
		global::vertex_subsurface = IntType(0);
	}
	
	void view_area_draw(ScopeAny self)
	{
		sReal(view_area_x) = sReal(panel_area_x) + ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"left"*/ STR(189)))->size_real_ani + ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"left_secondary"*/ STR(185)))->size_real_ani;
		sReal(view_area_y) = sReal(panel_area_y) + ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"top"*/ STR(188)))->size_real_ani;
		sReal(view_area_width) = sReal(panel_area_width) - ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"left"*/ STR(189)))->size_real_ani - ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"left_secondary"*/ STR(185)))->size_real_ani - ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"right"*/ STR(190)))->size_real_ani - ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"right_secondary"*/ STR(186)))->size_real_ani;
		sReal(view_area_height) = sReal(panel_area_height) - ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"top"*/ STR(188)))->size_real_ani - ObjType(obj_panel, DsMap(sInt(panel_map)).Value(/*"bottom"*/ STR(187)))->size_real_ani;
		view_draw(self, sInt(view_main));
		view_draw(self, sInt(view_second));
		if (sVar(window_busy) == /*"viewresizehor"*/ STR(3874) || sVar(window_busy) == /*"viewresizeboth"*/ STR(3875))
		{
			sInt(mouse_cursor) = cr_size_we;
			if (string_contains(ObjType(obj_view, sInt(view_second))->location, /*"left"*/ STR(189)))
				ObjType(obj_view, sInt(view_second))->width = sVar(view_resize_width) + (gmlGlobal::mouse_x - sInt(mouse_click_x));
			else
				ObjType(obj_view, sInt(view_second))->width = sVar(view_resize_width) - (gmlGlobal::mouse_x - sInt(mouse_click_x));
			
			ObjType(obj_view, sInt(view_second))->width = clamp(ObjType(obj_view, sInt(view_second))->width, IntType(364), sReal(view_area_width));
			if (!sBool(mouse_left))
				sVar(window_busy) = /*""*/ STR(0);
		}
		if (sVar(window_busy) == /*"viewresizever"*/ STR(3876) || sVar(window_busy) == /*"viewresizeboth"*/ STR(3875))
		{
			sInt(mouse_cursor) = cr_size_ns;
			if (string_contains(ObjType(obj_view, sInt(view_second))->location, /*"top"*/ STR(188)))
				ObjType(obj_view, sInt(view_second))->height = sVar(view_resize_height) + (gmlGlobal::mouse_y - sInt(mouse_click_y));
			else
				ObjType(obj_view, sInt(view_second))->height = sVar(view_resize_height) - (gmlGlobal::mouse_y - sInt(mouse_click_y));
			
			ObjType(obj_view, sInt(view_second))->height = clamp(ObjType(obj_view, sInt(view_second))->height, IntType(50), sReal(view_area_height));
			if (!sBool(mouse_left))
				sVar(window_busy) = /*""*/ STR(0);
		}
		if (sVar(window_busy) == /*"viewresizeboth"*/ STR(3875))
		{
			if (ObjType(obj_view, sInt(view_second))->location == /*"right"*/ STR(190) || ObjType(obj_view, sInt(view_second))->location == /*"left_secondary"*/ STR(185))
				sInt(mouse_cursor) = cr_size_nesw;
			else
				sInt(mouse_cursor) = cr_size_nwse;
			
		}
		if (sVar(window_busy) == /*"viewresizesplithor"*/ STR(3877))
		{
			sInt(mouse_cursor) = cr_size_we;
			sReal(view_split) = clamp((gmlGlobal::mouse_x - sReal(view_area_x)) / sReal(view_area_width), 0.1, 0.9);
			if (ObjType(obj_view, sInt(view_second))->location == /*"right"*/ STR(190))
				sReal(view_split) = IntType(1) - sReal(view_split);
			if (!sBool(mouse_left))
				sVar(window_busy) = /*""*/ STR(0);
		}
		if (sVar(window_busy) == /*"viewresizesplitver"*/ STR(3878))
		{
			sInt(mouse_cursor) = cr_size_ns;
			sReal(view_split) = clamp((gmlGlobal::mouse_y - sReal(view_area_y)) / sReal(view_area_height), 0.1, 0.9);
			if (ObjType(obj_view, sInt(view_second))->location == /*"bottom"*/ STR(187))
				sReal(view_split) = IntType(1) - sReal(view_split);
			if (!sBool(mouse_left))
				sVar(window_busy) = /*""*/ STR(0);
		}
	}
	
	void view_click(ScopeAny self, IntType view, VarType cam)
	{
		IntType surf;
		surf = surface_create((IntType)(sVar(content_width)), (IntType)(sVar(content_height)));
		global::render_camera = cam;
		global::render_ratio = (RealType)sVar(content_width) / sVar(content_height);
		surface_set_target(surf);
	{
		draw_clear(c_black);
		render_world_start();
		render_world(self, e_render_mode_CLICK);
		render_world_done();
	}
		surface_reset_target();
		VarType tl = surface_getpixel(surf, (IntType)(gmlGlobal::mouse_x - sVar(content_x)), (IntType)(gmlGlobal::mouse_y - sVar(content_y)));
		if (tl > IntType(0))
		{
			if (!(global::tl_edit > 0) && !keyboard_check(vk_control))
				while (idVar(tl, parent) != global::_app->id && !(idVar(idVar(tl, parent), lock) > 0) && tl_update_list_filter(idVar(tl, parent)))
					tl = idVar(tl, parent);
			
			action_tl_select(self, tl);
			if (sVar(setting_timeline_select_jump) > 0)
				tl_jump(tl);
		}
		else
			if (!keyboard_check(vk_shift))
				action_tl_deselect_all(self);
		
		surface_free(surf);
	}
	
	void view_control_bend(ScopeAny self, IntType view)
	{
		RealType len;
		VarType part, color;
		len = point3D_distance(global::cam_from, idVar(global::tl_edit, world_pos)) * view_3d_control_size * 0.4;
		part = idVar(global::tl_edit, model_part);
		for (IntType i = X_; i <= Z_; i++)
		{
			if (!idVec(part, bend_axis).Real(i))
				continue;
			MatrixType mat;
			if (i == X_)
			{
				color = global::c_control_cyan;
				mat = matrix_multiply(matrix_build(0.0, 0.0, 0.0, 0.0, 90.0, idVar(global::tl_edit, value).Value(e_value_BEND_ANGLE_Z) * idVec(part, bend_axis).Real(Z_), 1.0, 1.0, 1.0), idVar(global::tl_edit, matrix));
			}
			else
				if (i == Y_)
				{
					color = ((sReal(setting_z_is_up) > 0) ? global::c_control_yellow : global::c_control_magenta);
					mat = matrix_multiply(matrix_build(0.0, 0.0, 0.0, idVar(global::tl_edit, value).Value(e_value_BEND_ANGLE_X) * idVec(part, bend_axis).Real(X_) + 90.0, 0.0, idVar(global::tl_edit, value).Value(e_value_BEND_ANGLE_Z) * idVec(part, bend_axis).Real(Z_), 1.0, 1.0, 1.0), idVar(global::tl_edit, matrix));
				}
				else
				{
					color = ((sReal(setting_z_is_up) > 0) ? global::c_control_magenta : global::c_control_yellow);
					mat = matrix_multiply(matrix_build(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0), idVar(global::tl_edit, matrix));
				}
			
			
			matrix_remove_scale(VarType::CreateRef(mat));
			view_control_rotate_axis(self, view, e_view_control_BEND_X + i, e_value_BEND_ANGLE_X + i, color, mat, len);
		}
		if (sVar(window_busy) == /*"rendercontrol"*/ STR(31) && sInt(view_control_edit_view) == view && sInt(view_control_edit) >= e_view_control_BEND_X && sInt(view_control_edit) <= e_view_control_BEND_Z)
		{
			sInt(mouse_cursor) = cr_handpoint;
			if (!(sInt(mouse_still) > 0))
			{
				RealType ang, prevang, rot, snapval, mul;
				VarType move;
				global::axis_edit = sInt(view_control_edit) - e_view_control_BEND_X;
				ang = point_direction(gmlGlobal::mouse_x - sVar(content_x), gmlGlobal::mouse_y - sVar(content_y), sVec(view_control_pos).Real(X_), sVec(view_control_pos).Real(Y_));
				prevang = point_direction(sVar(mouse_previous_x) - sVar(content_x), sVar(mouse_previous_y) - sVar(content_y), sVec(view_control_pos).Real(X_), sVec(view_control_pos).Real(Y_));
				rot = (angle_difference_fix(ang, prevang) * negate(sReal(view_control_flip)) * negate(idVec(part, bend_invert).Real(global::axis_edit)) * negate(global::axis_edit == X_)) * sReal(dragger_multiplier);
				mul = min({ IntType(1), (idVec(part, bend_direction_max).Real(global::axis_edit) - idVec(part, bend_direction_min).Real(global::axis_edit)) / 90.0 });
				snapval = ((sReal(dragger_snap) > 0) ? sReal(setting_snap_size_rotation) : snap_min);
				sReal(view_control_move_distance) += rot * mul;
				move = sReal(view_control_move_distance);
				if (!(sVar(setting_snap_absolute) > 0) && sReal(dragger_snap) > 0)
					move = snap(move, snapval);
				move += sVar(view_control_value);
				move = tl_value_clamp(e_value_BEND_ANGLE_X + global::axis_edit, move);
				if (sVar(setting_snap_absolute) > 0 || !(sReal(dragger_snap) > 0))
					move = snap(move, snapval);
				move -= idVar(global::tl_edit, value).Value(e_value_BEND_ANGLE_X + global::axis_edit);
				tl_value_set_start(self, ID_action_tl_frame_bend_angle, true);
				tl_value_set(self, { e_value_BEND_ANGLE_X + global::axis_edit, move, true });
				tl_value_set_done();
			}
			if (!sBool(mouse_left))
			{
				sVar(window_busy) = /*""*/ STR(0);
				sInt(view_control_edit) = null_;
				sVar(view_control_matrix) = null_;
				sVar(view_control_length) = null_;
				sReal(view_control_move_distance) = IntType(0);
				sVar(view_control_value) = IntType(0);
			}
		}
	}
	
}
